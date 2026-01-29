#pragma once
#include <Geode/Geode.hpp>

// Memory patches to enable practice mode music sync
// These patches target specific functions in GD that disable music sync

struct PracticeMusicPatches {
    // Patch the function that mutes/desyncs music in practice mode
    static void applyMusicSyncPatch() {
        #ifdef GEODE_IS_WINDOWS
            // Windows-specific patches for v5.0.0-alpha.1
            // These addresses need to be updated for the exact version
            // (string reference to "practice" music mute function)
            const uintptr_t PRACTICE_MUSIC_FUNC = 0x00400000; // Example address
            
            // NOP the call that mutes practice music
            patchPracticeMusicFunction();
            
        #elif defined(GEODE_IS_MACOS)
            // macOS-specific patches
            patchPracticeMusicFunctionMac();
            
        #elif defined(GEODE_IS_ANDROID)
            // Android-specific patches
            patchPracticeMusicFunctionAndroid();
            
        #elif defined(GEODE_IS_IOS)
            // iOS-specific patches
            patchPracticeMusicFunctionIOS();
        #endif
    }
    
private:
    // Platform-specific patching implementations
    static void patchPracticeMusicFunction() {
        // Windows implementation
        auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));
        
        // Find and patch the practice music disable function
        // This is a simplified example - actual patching requires
        // reverse engineering the specific version
        
        log::info("Attempting to patch practice music function...");
        
        // Example patch (this would need actual addresses):
        // uintptr_t addr = base + 0x123456;
        // patch(addr, {0x90, 0x90, 0x90}); // NOP the disable instruction
    }
    
    static void patchPracticeMusicFunctionMac() {
        // Similar implementation for macOS
    }
    
    static void patchPracticeMusicFunctionAndroid() {
        // Similar implementation for Android
    }
    
    static void patchPracticeMusicFunctionIOS() {
        // Similar implementation for iOS
    }
};

// Apply patches when mod loads
$execute {
    PracticeMusicPatches::applyMusicSyncPatch();
}
