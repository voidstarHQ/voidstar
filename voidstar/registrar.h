#pragma once

#include <cassert>
#include <functional>
#include <map>
#include <string>
#include <vector>

// Make sure my_type's cc_library has the settng:
// alwayslink = 1,  # For registration

/*
  Declare registry (in my_type.h):
  REGISTRY_DECLARATION_FOR(MyType, std::shared_ptr<MyType>());
  #define REGISTER_MyType(NAME, KLASS) \
    REGISTRY_REGISTER_FOR(                \
        MyType, NAME, KLASS, () { return std::make_shared<KLASS>(); })
*/

#define REGISTRY_DECLARATION_FOR(FOR, FUNC)                              \
  using FOR##FactoryFunc = std::function<FUNC>;                          \
  void Register##FOR(const std::string& name, FOR##FactoryFunc factory); \
  FOR##FactoryFunc Registered##FOR(const std::string& name);             \
  const std::map<const std::string, FOR##FactoryFunc>& RegistryFor##FOR()

// https://stackoverflow.com/a/2390626/1418165
#ifdef __cplusplus
#define INITIALIZER(f)    \
  static void f(void);    \
  struct f##_t_ {         \
    f##_t_(void) { f(); } \
  };                      \
  static f##_t_ f##_;     \
  static void f(void)
#elif defined(_MSC_VER)
#pragma section(".CRT$XCU", read)
#define INITIALIZER2_(f, p)                                \
  static void f(void);                                     \
  __declspec(allocate(".CRT$XCU")) void (*f##_)(void) = f; \
  __pragma(comment(linker, "/include:" p #f "_")) static void f(void)
#ifdef _WIN64
#define INITIALIZER(f) INITIALIZER2_(f, "")
#else
#define INITIALIZER(f) INITIALIZER2_(f, "_")
#endif
#else
#define INITIALIZER(f)                              \
  static void f(void) __attribute__((constructor)); \
  static void f(void)
#endif

#define REGISTRY_REGISTER_FOR(FOR, NAME, KLASS, FACT) \
  INITIALIZER(Registering##KLASS) {                   \
    auto factory = [] FACT;                           \
    Register##FOR(NAME, factory);                     \
  }

/*
  Implement registry (in my_type.cc):
  REGISTRY_IMPLEMENTATION_FOR(MyType)
*/

#define REGISTRY_IMPLEMENTATION_FOR(FOR)                                       \
  std::map<const std::string, FOR##FactoryFunc>& RegistrarOfMany##FOR() {      \
    static std::map<const std::string, FOR##FactoryFunc> registrar;            \
    return registrar;                                                          \
  }                                                                            \
                                                                               \
  void Register##FOR(const std::string& name, FOR##FactoryFunc factory) {      \
    assert(factory);                                                           \
    decltype(auto) registrar = RegistrarOfMany##FOR();                         \
    assert(registrar.find(name) == registrar.end());                           \
    registrar[name] = factory;                                                 \
    assert(RegistrarOfMany##FOR().find(name) != RegistrarOfMany##FOR().end()); \
  }                                                                            \
                                                                               \
  FOR##FactoryFunc Registered##FOR(const std::string& name) {                  \
    const auto& registrar = RegistrarOfMany##FOR();                            \
    const auto& it = registrar.find(name);                                     \
    return (it != registrar.end()) ? it->second : nullptr;                     \
  }                                                                            \
                                                                               \
  const std::map<const std::string, FOR##FactoryFunc>& RegistryFor##FOR() {    \
    return RegistrarOfMany##FOR();                                             \
  }
