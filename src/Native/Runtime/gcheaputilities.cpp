// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

#include "common.h"
#include "gcenv.h"
#include "gcheaputilities.h"
#include "gchandleutilities.h"

// This is the global GC heap, maintained by the VM.
GPTR_IMPL(IGCHeap, g_pGCHeap);

// These globals are variables used within the GC and maintained
// by the EE for use in write barriers. It is the responsibility
// of the GC to communicate updates to these globals to the EE through
// GCToEEInterface::StompWriteBarrier.
GPTR_IMPL_INIT(uint32_t, g_card_table,      nullptr);
GPTR_IMPL_INIT(uint8_t,  g_lowest_address,  nullptr);
GPTR_IMPL_INIT(uint8_t,  g_highest_address, nullptr);
GVAL_IMPL_INIT(GCHeapType, g_heap_type,     GC_HEAP_INVALID);
uint8_t* g_ephemeral_low  = (uint8_t*)1;
uint8_t* g_ephemeral_high = (uint8_t*)~0;

#ifdef FEATURE_MANUALLY_MANAGED_CARD_BUNDLES
uint32_t* g_card_bundle_table = nullptr;
#endif

IGCHandleManager* g_pGCHandleManager = nullptr;

GcDacVars g_gc_dac_vars;
GPTR_IMPL(GcDacVars, g_gcDacGlobals);
