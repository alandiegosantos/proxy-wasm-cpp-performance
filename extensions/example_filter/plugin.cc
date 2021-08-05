#include "extensions/example_filter/plugin.h"

// WASM_PROLOG
#ifndef NULL_PLUGIN
// #include "contrib/proxy_expr.h"
#include "proxy_wasm_intrinsics.h"

#else  // NULL_PLUGIN

#include "include/proxy-wasm/null_plugin.h"

namespace proxy_wasm {
namespace null_plugin {

#endif  // NULL_PLUGIN

namespace Example {

// END WASM_PROLOG

FilterHeadersStatus PluginContext::onResponseHeaders(uint32_t, bool) {

    addResponseHeader("X-Wasm-custom", "FOO");

    return FilterHeadersStatus::Continue;

}

#ifdef NULL_PLUGIN
NullPluginRegistry* context_registry_{};

RegisterNullVmPluginFactory register_stats_filter("envoy.wasm.example", []() {
  return std::make_unique<NullPlugin>(context_registry_);
});

#endif

} // namespace Example

// WASM_EPILOG
#ifdef NULL_PLUGIN
}  // namespace null_plugin
}  // namespace proxy_wasm
#endif  // NULL_PLUGIN