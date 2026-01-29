#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include "patches.hpp"

using namespace geode::prelude;

// Mod entry point
$on_mod(Loaded) {
    log::info("Practice Music Sync mod loaded!");
}

// Main modification to PlayLayer
class $modify(PlayLayer) {
    struct Fields {
        bool m_wasPracticeMusicSync = false;
    };

    // Override the function that disables music sync in practice
    void togglePracticeMode(bool practice) {
        // Store original practice mode state
        bool wasPractice = m_isPracticeMode;
        
        // Call original function
        PlayLayer::togglePracticeMode(practice);
        
        // If entering practice mode from normal mode
        if (practice && !wasPractice) {
            // Enable music sync
            if (m_fields->m_wasPracticeMusicSync) {
                this->enablePracticeModeMusicSync();
            }
        }
    }
    
    // Enable music sync in practice mode
    void enablePracticeModeMusicSync() {
        // This is where we patch the music sync behavior
        // The actual patch is in the patches.hpp file
        log::info("Practice mode music sync enabled");
    }
    
    // Override reset level to maintain music sync
    void resetLevel() {
        PlayLayer::resetLevel();
        
        // Re-enable music sync if in practice mode
        if (m_isPracticeMode && m_fields->m_wasPracticeMusicSync) {
            this->enablePracticeModeMusicSync();
        }
    }
};
