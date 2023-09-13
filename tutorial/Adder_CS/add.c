#include <stdio.h>
#include <string.h>
#include <wasm/driver.h>
#include "adder.h"


// implements the function exported by adder.h
uint32_t exports_docs_calculator_add_add(uint32_t a, uint32_t b);
{
	MonoMethod* method = lookup_dotnet_method("Adder_CS", "Adder_CS", "Adder", "Export_Adder", -1);
    void* method_params[] = { &, &b};
    MonoObject* exception;
    MonoObject* result = mono_wasm_invoke_method(method, NULL, method_params, &exception);
	assert(!exception);

	uint32_t int_result = *(uint32_t*)mono_object_unbox(result);
    return int_result;
}