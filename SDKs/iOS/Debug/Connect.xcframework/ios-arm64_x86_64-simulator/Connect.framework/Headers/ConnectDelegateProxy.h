//
// Copyright (C) 2026 Acoustic, L.P. All rights reserved.
//
// NOTICE: This file contains material that is confidential and proprietary to
// Acoustic, L.P. and/or other developers. No license is granted under any
// intellectual or industrial property rights of Acoustic, L.P. except as may
// be provided in an agreement with Acoustic, L.P. Any unauthorized copying or
// distribution of content from this file is prohibited.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// Block called with the raw APNs device token when registration succeeds.
typedef void (^ConnectTokenHandler)(NSData *token);

/// Block called with the error when APNs registration fails.
typedef void (^ConnectTokenFailureHandler)(NSError *error);

/**
 * Transparent proxy that wraps the app's existing UIApplicationDelegate,
 * intercepts APNs token callbacks, and forwards all other delegate messages
 * unchanged.
 *
 * Used by ConnectPush in `.automatic` mode so the SDK receives the APNs
 * device token without requiring any AppDelegate code in the client app.
 * Works with both UIKit apps (existing AppDelegate) and SwiftUI apps (no
 * AppDelegate), because UIApplication.shared.delegate is always set by the
 * time enable() is called.
 *
 * The caller must retain the returned proxy — UIApplication.delegate is a
 * weak reference and will not keep it alive on its own.
 */
@interface ConnectDelegateProxy : NSObject <UIApplicationDelegate>

/**
 * Replaces UIApplication's current delegate with a proxy that wraps it.
 *
 * @param application    The shared UIApplication instance.
 * @param tokenHandler   Called on the main thread when APNs delivers a token.
 * @param failureHandler Called on the main thread when APNs registration fails.
 * @return The installed proxy. The caller must hold a strong reference.
 */
+ (instancetype)installOnApplication:(UIApplication *)application
                         tokenHandler:(ConnectTokenHandler)tokenHandler
                       failureHandler:(ConnectTokenFailureHandler)failureHandler
    NS_SWIFT_NAME(install(on:tokenHandler:failureHandler:));

/**
 * Restores the original delegate to UIApplication and clears callbacks.
 *
 * Call this before releasing the proxy so UIApplication.delegate is not
 * left pointing to nil.
 *
 * @param application The shared UIApplication instance.
 */
- (void)uninstallFromApplication:(UIApplication *)application
    NS_SWIFT_NAME(uninstall(from:));

@end

NS_ASSUME_NONNULL_END
