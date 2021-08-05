#pragma once

#include <unordered_map>

// WASM_PROLOG
#ifndef NULL_PLUGIN
#include "proxy_wasm_intrinsics.h"

#else  // NULL_PLUGIN

#include "include/proxy-wasm/null_plugin.h"

namespace proxy_wasm {
namespace null_plugin {

#endif  // NULL_PLUGIN

namespace Example {

// END WASM_PROLOG

class PluginRootContext : public RootContext {
public:
  explicit PluginRootContext(uint32_t id, std::string_view root_id) : RootContext(id, root_id) {}

};

class PluginContext : public Context {
public:
  explicit PluginContext(uint32_t id, RootContext *root) : Context(id, root) {}

  FilterHeadersStatus onResponseHeaders(uint32_t context_id, bool end_of_stream) override;
    
};


#ifdef NULL_PLUGIN
PROXY_WASM_NULL_PLUGIN_REGISTRY;
#endif

static RegisterContextFactory register_Example(
    CONTEXT_FACTORY(PluginContext),
    ROOT_FACTORY(PluginRootContext), "example");

} // namespace Example

// WASM_EPILOG
#ifdef NULL_PLUGIN
}  // namespace null_plugin
}  // namespace proxy_wasm
#endif  // NULL_PLUGIN