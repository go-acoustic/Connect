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
 * Intercepts APNs token callbacks on the app's existing UIApplicationDelegate
 * without replacing or wrapping it.
 *
 * Used by ConnectPush in `.automatic` mode so the SDK receives the APNs
 * device token without requiring any AppDelegate code in the client app.
 *
 * When a current delegate exists, the proxy isa-swizzles the delegate instance:
 * the original pointer stays in UIApplication.delegate and a dynamic ObjC
 * subclass intercepts only the two APNs callbacks. All other
 * UIApplicationDelegate methods — including scene-lifecycle callbacks — continue
 * to dispatch through the original class hierarchy unchanged.
 *
 * When no current delegate exists (rare), the proxy installs itself as the
 * delegate. The caller must retain the returned proxy in that case because
 * UIApplication.delegate is a weak reference.
 */
@interface ConnectDelegateProxy : NSObject <UIApplicationDelegate>

/**
 * Installs APNs token interception on UIApplication's current delegate.
 *
 * When a delegate is already present the method isa-swizzles it in-place;
 * UIApplication.delegate is not changed. When no delegate is present the
 * proxy installs itself as the delegate — the caller must hold a strong
 * reference to it in that case.
 *
 * @param application    The shared UIApplication instance.
 * @param tokenHandler   Called on the main thread when APNs delivers a token.
 * @param failureHandler Called on the main thread when APNs registration fails.
 * @return The installed proxy. The caller must hold a strong reference when
 *         no prior delegate existed (UIApplication.delegate is weak).
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
