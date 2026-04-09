//
// Copyright (C) 2025 Acoustic, L.P. All rights reserved.
//
// NOTICE: This file contains material that is confidential and proprietary to
// Acoustic, L.P. and/or other developers. No license is granted under any intellectual or
// industrial property rights of Acoustic, L.P. except as may be provided in an agreement with
// Acoustic, L.P. Any unauthorized copying or distribution of content from this file is
// prohibited.
//
//  TLFApplicationHelper.h
//  Connect
//
//  Created by Omar Hernandez on 4/26/24.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import <Tealeaf/TLFPublicDefinitions.h>
#import <Tealeaf/TLFApplicationHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface ConnectApplicationHelper : NSObject//TLFApplicationHelper

/*!
 * @abstract Returns the common application helper.
 * @return  Returns the common application helper, used to manage the flow and lifecycle of the application and Connect.
 * @note Deprecated. Use ConnectSDK.shared instead.
 */
+ (ConnectApplicationHelper *)sharedInstance;

/*!
 * @abstract Turns on the Connect framework
 * @return Returns YES or NO based on whether the framework was successfully enabled or not.
 * @note Deprecated. Use ConnectSDK.shared.enable(appKey:postURL:) instead.
 */
- (BOOL)enableFramework;

/*!
 * @abstract Turns on the Tealeaf framework for unit tests
 * @return Returns YES or NO based on whether the framework was successfully enabled or not and update values.
 */
- (BOOL)enableTealeafFrameworkForUnitTests;

/*!
 * @abstract Turns on the Connect framework
 * @param appKey - The string representation of the application key.
 * @param postUrl - The string representation of the post message URL, colloector, target page.
 * @return Returns YES or NO based on whether the framework was successfully enabled or not and update values.
 * @note Deprecated. Use ConnectSDK.shared.enable(appKey:postURL:) instead.
 */
- (BOOL)enableFramework:(NSString *)appKey withPostMessageUrl:(NSString *)postUrl;

/**
 * @abstract Turns off the Connect Framework.
 * @return Returns YES or NO based on whether the framework was successfully enabled or not.
 * @note Deprecated. Use ConnectSDK.shared.disable() instead.
 */
- (BOOL)disableFramework;

/**
 * @abstract Turns off the Tealeaf Framework for unit tests.
 * @return Returns YES or NO based on whether the framework was successfully enabled or not.
 */
- (BOOL)disableTealeafFrameworkForUnitTests;

/*!
 * @abstract Set up react native flag.
 * @param isReactN - Whether it is a react native application.
 * @param usesWrapNavCon - Whether it uses Connect wrapper from react native plugin.
 * @return Returns YES or NO based on whether it is react native.
 * @note Deprecated. Use ConnectSDK.shared.setReactNative(_:wrapNavigationContainer:) instead.
 */
- (BOOL)isReactNative:(BOOL)isReactN wrapNavigationContainer:(BOOL)usesWrapNavCon;

/*!
 * @abstract Set current logical page name.
 * @param logicalPageName - Logical page name.
 * @return Returns YES or NO it was able to update.
 * @note Deprecated. Use ConnectSDK.shared.setCurrentScreen(pageName:) instead.
 */
- (BOOL)setCurrentScreenName:(NSString *)logicalPageName;

/*!
 * @abstract Pauses capture of data on the Connect framework
 * @return Returns YES or NO based on whether the framework was successfully paused or not.
 * @note Deprecated. Use ConnectSDK.shared.pause() instead.
 */
- (BOOL)pause;

/**
 * @abstract Resumes capture of data on the Connect framework
 * @return Returns YES or NO based on whether the framework was successfully resumed or not.
 * @note Deprecated. Use ConnectSDK.shared.resume() instead.
 */
- (BOOL)resume;

/**
 * @abstract Resumes capture of data on the Connect framework
 * @param pageName - The current page name to be used.
 * @return Returns YES or NO based on whether the framework was successfully resumed or not.
 * @note Deprecated. Use ConnectSDK.shared.resume(pageName:) instead.
 */
- (BOOL)resume:(NSString *)pageName;

/**
 Setup the Kill Switch URL. This is the URL to be checked when the framework initializes. If the page is not reachable the framework will not initialize. Setting the URL will update the configurable plist file for that user's device.
 @param value - The string representation of the new Kill Switch URL.
 @note Deprecated. Use ConnectSDK.shared.setKillSwitchURL(_:) instead.
 */
- (void)setKillSwitchUrl:(NSString *)value;

/**
 Setup the Post Message URL. The URL for posting data to your server. Setting the URL will update the configurable plist file for that user's device.
 @param value - The string representation of the new Target Page URL.
 @note Deprecated. Use ConnectSDK.shared.setPostMessageURL(_:) instead.
 */
- (void)setPostMessageUrl:(NSString *)value;

/**
 Requests that the framework post to the server as soon as possible. It is a good idea to call this method after you have finished your own network transmissions. The device shuts down the Wi-Fi and cell radios when there is no activity. NOTE: In TLFConfigurableItems.plist ManualPostEnabled must be set to YES.
 @note Deprecated. Use ConnectSDK.shared.requestManualPost() instead.
 */
- (void)requestManualServerPost;

/**
 Starts a new Tealeaf Session. For example, if you want a new session to begin after every successful purchase.
 @return if the Tealeaf session successful started or not.
 @note Deprecated. Use ConnectSDK.shared.startNewSession() instead.
 */
- (BOOL)startNewTLFSession;

/**
 Returns the current session ID.
 @return the current Tealeaf session ID
 @note Deprecated. Use ConnectSDK.shared.currentSessionId instead.
 */
- (NSString *)currentSessionId;

/**
 Returns a BOOL value indicating if the Connect Framework is enabled or not.
 @return If the Connect Framework is enabled or not.
 @note Deprecated. Use ConnectSDK.shared.isEnabled instead.
 */
- (BOOL)isTLFEnabled;

/**
 Returns a string variable which represents the Connect Framework version.
 @return The string representation of the Connect Framework version.
 @note Deprecated. Use ConnectSDK.shared.frameworkVersion instead.
 */
- (NSString *)frameworkVersion;

/**
 Sets logging level for an event. Event names are listed in TLFEventsLevels.plist. If you call this method for an event not listed in the TLFEventsLevels.plist then the set will fail.
 @param logLevel - the kTLFMonitoringLevelType (unsigned integer) for the event specified.
 @param event - the string representation of the event.
 @return if the logging level was successfully update or not.
 @note Deprecated. Use ConnectSDK.shared.setLogLevel(_:forEvent:) instead.
 */
- (BOOL)setLogLevel:(NSUInteger)logLevel forEvent:(NSString *)event;

/**
 Gets logging level for an event. If the event is not found kTLFMonitoringLevel0 is returned. Event names are listed in TLFEventsLevels.plist.
 @param event - the string representation of the event
 @return the kTLFMonitoringLevelType (unsigned integer) for the event specified.
 @note Deprecated. Use ConnectSDK.shared.logLevel(forEvent:) instead.
 */
- (NSUInteger)logLevelForEvent:(NSString *)event;

/**
 Sets the value of a configurable item in TLFConfigurableItems.plist file. This will only update the in memory value.
 @param configItem - the name of the configurable item. See TLFConfigurableItems.plist for a list of items.
 @param value - the new value of the configurable item.
 @return if the configurable item was successfully update or not.
 @note Deprecated. Use ConnectSDK.shared.setConfigurableItem(_:value:) or ConnectConfig.advanced instead.
 */
- (BOOL)setConfigurableItem:(NSString *)configItem value:(id)value;

/**
 Gets value of a configurable item either from TLFConfigurableItems.plist file or in memory data structure.
 @param configItem - the name of the configurable item. See TLFConfigurableItems.plist for a list of items.
 @return the value of the configurable item.
 @note Deprecated. Use ConnectSDK.shared.valueForConfigurableItem(_:) instead.
 */
- (nullable id)valueForConfigurableItem:(NSString *)configItem;

/**
 Setup the Device ID.
 @param value - the string which represents the new Device ID.
 @return if the Device ID was successfully updated or not.
 @note Deprecated. Use ConnectSDK.shared.setDeviceId(_:) instead.
 */
- (BOOL)setDeviceId:(NSString *)value;

/**
 Returns a string representation of the Device ID.
 @return a string representation of the Device ID.
 @note Deprecated. Use ConnectSDK.shared.deviceId instead.
 */
- (NSString *)getDeviceId;

/**
 Setup the advertising ID that is used in conjunction with CXA.
 @param value - the string which represents the advertising ID.
 @return if the advertising ID was successfully updated or not.
 @note Deprecated. Use ConnectSDK.shared.setCXAAdvertisingId(_:) instead.
 */
- (BOOL)setCXAAdvertisingId:(NSString *)value;

/**
 Returns a string representation of the advertising ID.
 @return a string representation of the advertising ID.
 @note Deprecated. Use ConnectSDK.shared.cxaAdvertisingId instead.
 */
- (nullable NSString *)getCXAAdvertisingId;

/**
 Returns a string representation of the current application context.
 @return a string representation of the current application context.
 @note Deprecated. Use ConnectSDK.shared.applicationContextName instead.
 */
- (nullable NSString *)applicationContextName;

/**
 Set any application specific headers into each HTTP request to PostMessageUrl
 @param headers - Dictionary of headers with key value pairs to be sent over the HTTP Request.
 @note Deprecated. Use ConnectSDK.shared.setHTTPHeaders(_:) instead.
 */
- (void)setAdditionalHttpHeaders:(nullable NSMutableDictionary *)headers;

/**
 Set an application specific header into each HTTP request to PostMessageUrl
 @param name - Header key name to be sent over the HTTP Request.
 @param value - Header value to be sent over the HTTP Request.
 @note Deprecated. Use ConnectSDK.shared.addHTTPHeader(_:forName:) instead.
 */
- (void)addAdditionalHttpHeader:(NSString *)value forName:(NSString *)name;

/**
 Set any application specific cookies into each HTTP request to PostMessageUrl
 @param cookies - Array of NSHTTPCookie objects to be sent over the HTTP Request.
 @note Deprecated. Use ConnectSDK.shared.setHTTPCookies(_:) instead.
 */
- (void)setAdditionalHttpCookies:(NSMutableArray *)cookies;

/**
 Set any application specific cookie into each HTTP request to PostMessageUrl
 @param cookie - NSHTTPCookie object to be sent over the HTTP Request.
 @note Deprecated. Use ConnectSDK.shared.addHTTPCookie(_:) instead.
 */
- (void)addAdditionalHttpCookie:(nullable NSHTTPCookie *)cookie;

/**
 Get all HTTP Headers that are sent with each HTTP request to PostMessageUrl
 @return Dictonary of HTTP Headers as key value pairs.
 @note Deprecated. Use ConnectSDK.shared.httpHeaders instead.
 */
- (NSDictionary *)getAdditionalHttpHeaders;

/**
 Get all HTTP cookies that are sent with each HTTP request to PostMessageUrl
 @return Array of HTTP Cookies as NSHTTPCookie objects.
 @note Deprecated. Use ConnectSDK.shared.httpCookies instead.
 */
- (nullable NSArray *)getAdditionalHttpCookies;

/**
 Add session cookie to given NSMutableURLRequest object. Typically used when manually instrumenting the application.
 @param request - NSMutableURLRequest object to be sessionized.
 @return YES when successful else NO.
 @note Deprecated. Use ConnectSDK.shared.sessionize(request:) instead.
 */
- (BOOL)sessionizeRequest:(nullable NSMutableURLRequest *)request;

/**
 Confirms if given NSURLRequest coming from javascript is a Connect request URL. Typically used when manually instrumenting the application.
 @param request - NSMutableURLRequest object to be checked if is a Tealeaf request URL.
 @param webView - WKWebView object which contains Tealeaf hybrid bridge javascript code.
 @return YES when Tealeaf hybrid bridge request else NO.
 @note Deprecated. Use ConnectSDK.shared.isHybridBridgeRequest(_:webView:) instead.
 */
- (BOOL)isConnectHybridBridgeRequest:(nullable NSURLRequest *)request webView:(nullable id)webView;

/**
 Injects Connect hybrid bridge javascript code into the webpage loaded into WKWebView. Typically used when manually instrumenting the application.
 @param webView - WKWebView object into which Tealeaf hybrid bridge javascript code needs to be injected.
 @return YES when Tealeaf hybrid bridge javascript code injection is successful request else NO.
 @note Deprecated. Use ConnectSDK.shared.injectHybridBridge(into:) instead.
 */
- (BOOL)InjectConnectHybridBridgeOnWebViewDidFinishLoad:(nullable id)webView;

/**
 UIApplication sendEvent API which needs to be overriden in case developers are using their own class derived from UIApplication. Please see UIApplication documentation for details.
 @param event - UIEvent object that application will be processing.
 @note Deprecated. Use ConnectSDK.shared.sendEvent(_:) instead.
 */
- (void)sendEvent:(nullable UIEvent *)event;

/**
 UIApplication sendAction API which needs to be overriden in case developers are using their own class derived from UIApplication. Please see UIApplication documentation for details.
 @param action - selector of the event/action handler.
 @param target - UIView or UIControl that received the action.
 @param sender - UIView or UIControl that sent the action.
 @param event - UIEvent object that application will be processing.
 @note Deprecated. Use ConnectSDK.shared.sendAction(_:to:from:for:) instead.
 */
- (void)sendAction:(SEL)action to:(nullable id)target from:(nullable id)sender forEvent:(nullable UIEvent *)event;

/**
 Requests that the framework returns the AutoLayoutConfiguration set by user
 @return Dictionary of configuration items in TealeafLayoutConfig.json file for AutoLayout
 @note Deprecated. Use ConnectSDK.shared.layoutConfigItems instead.
 */
- (nullable NSDictionary *)layoutConfigItems;

@end

NS_ASSUME_NONNULL_END

// ---------------------------------------------------------------------------
// SDK-internal API — not part of the public developer interface.
// These methods are called by the Swift ConnectSDK layer to avoid triggering
// deprecation warnings on the public surface above. App developers should not
// call these methods directly; use ConnectSDK.shared instead.
// ---------------------------------------------------------------------------

/**
 * Internal category on ConnectApplicationHelper providing the stable call path
 * used by the Swift ConnectSDK layer.
 *
 * These methods avoid the deprecated public API surface while keeping a single
 * implementation path. The underscore prefix signals SDK-internal use only —
 * app developers should not call these methods directly.
 *
 * The deprecated public methods in ConnectApplicationHelper.h delegate to these
 * same methods, ensuring a single implementation path.
 */
NS_ASSUME_NONNULL_BEGIN

@interface ConnectApplicationHelper (Internal)

/// Returns the shared `ConnectApplicationHelper` instance without triggering
/// the deprecation warning on the public `sharedInstance` factory method.
///
/// All SDK-internal Swift code must use this method instead of `sharedInstance`
/// to avoid polluting the build log with spurious deprecation warnings that
/// are intended only for app developers.
+ (ConnectApplicationHelper *)_connectSharedInstance;

/// Pre-populates `EOCore.tempConfigDict` with the default values from the
/// standard config bundles for both the `EOCore` and `TLFCoreModule` modules.
///
/// Call this before `_connectEnableWithAppKey:postURL:` so that `loadConfig:`
/// succeeds even when `EOCoreSettings.bundle` and `TLFResources.bundle` are
/// absent from the app target.  Values written here are overridden by bundle
/// values (if the bundle is present) and then again by any programmatic
/// overrides supplied via `ConnectConfig`.
- (void)_connectApplyBundleDefaults;

/// Testable variant of `_connectApplyBundleDefaults`.
///
/// - Parameter bundleExists: A block that receives a bundle name (without the
///   `.bundle` extension) and returns `YES` if that bundle is present in the
///   app. Pass a block that consults `Bundle.main` in production, or a stub
///   that returns a fixed value in tests.
- (void)_connectApplyBundleDefaultsWithBundleExists:(BOOL (^)(NSString *bundleName))bundleExists;

/// Enables the framework with explicit credentials.
/// Equivalent to the public `enableFramework:withPostMessageUrl:` without compiler warnings.
- (BOOL)_connectEnableWithAppKey:(NSString *)appKey postURL:(NSString *)postURL;

/// Enables the framework in unit-test mode (no network, no kill-switch).
/// Equivalent to the public `enableTealeafFrameworkForUnitTests` without compiler warnings.
- (BOOL)_connectEnableForUnitTests;

/// Disables the framework after unit tests.
/// Equivalent to the public `disableTealeafFrameworkForUnitTests` without compiler warnings.
- (BOOL)_connectDisableForUnitTests;

/// Disables the framework.
/// Equivalent to the public `disableFramework` without compiler warnings.
- (BOOL)_connectDisable;

/// Returns whether the framework is currently enabled.
/// Equivalent to the public `isTLFEnabled` without compiler warnings.
- (BOOL)_connectIsEnabled;

/// Returns whether the framework is both enabled AND ready to log messages.
///
/// This is a stronger check than `_connectIsEnabled`. The underlying framework
/// sets `isEnabled = YES` before the asynchronous kill-switch check completes.
/// Calling `TLFSessionManager.getCurrentSessionId()` in that window spawns a
/// spurious session that does not match the one created by `startNewSession()`.
/// This method additionally checks `hasKillSwitchCompleted`, which is only set
/// to `YES` inside `startTealeafLibrary` — after `startNewSession()` has run —
/// guaranteeing a valid session ID exists before any message is logged.
- (BOOL)_connectIsReadyForLogging;

/// Returns the Connect framework version string.
/// Equivalent to the public `frameworkVersion` without compiler warnings.
- (NSString *)_connectFrameworkVersion;

/// Sets a single configurable item in the SDK configuration store.
///
/// This is the non-deprecated internal call path for config writes.
/// The Swift `ConnectSDK.enable(with:)` method uses this to apply
/// `ConnectConfig` fields without compiler warnings on
/// the public `setConfigurableItem:value:` method.
///
/// - Parameters:
///   - key:   The configuration key string (e.g. `"CompressPostMessage"`).
///   - value: The value to set. Must be a type supported by the EOCore
///            configuration system (`NSNumber`, `NSString`, `NSDictionary`,
///            `NSArray`).
- (BOOL)_connectSetConfigItem:(NSString *)key value:(id)value;

/// Gets a single configurable item from the SDK configuration store.
/// Equivalent to the public `valueForConfigurableItem:` without compiler warnings.
- (nullable id)_connectGetConfigItem:(NSString *)key;

// MARK: – Session

/// Pauses data capture. Equivalent to the public `pause` without compiler warnings.
- (BOOL)_connectPause;

/// Resumes data capture. Equivalent to the public `resume` without compiler warnings.
- (BOOL)_connectResume;

/// Resumes data capture and sets the current page name.
/// Equivalent to the public `resume:` without compiler warnings.
- (BOOL)_connectResumeWithPageName:(NSString *)pageName;

/// Sets the logical page name for the current screen.
/// Equivalent to the public `setCurrentScreenName:` without compiler warnings.
- (BOOL)_connectSetCurrentScreenName:(NSString *)logicalPageName;

/// Starts a new Connect session.
/// Equivalent to the public `startNewTLFSession` without compiler warnings.
- (BOOL)_connectStartNewSession;

/// Returns the current session identifier.
/// Equivalent to the public `currentSessionId` without compiler warnings.
- (nullable NSString *)_connectCurrentSessionId;

/// Sets the kill-switch URL.
/// Equivalent to the public `setKillSwitchUrl:` without compiler warnings.
- (void)_connectSetKillSwitchURL:(NSString *)url;

/// Sets the post-message URL.
/// Equivalent to the public `setPostMessageUrl:` without compiler warnings.
- (void)_connectSetPostMessageURL:(NSString *)url;

/// Requests a manual server post.
/// Equivalent to the public `requestManualServerPost` without compiler warnings.
- (void)_connectRequestManualPost;

/// Configures React Native mode.
/// Equivalent to the public `isReactNative:wrapNavigationContainer:` without compiler warnings.
- (BOOL)_connectSetReactNative:(BOOL)isReactNative
         wrapNavigationContainer:(BOOL)wrapNavigationContainer;

// MARK: – Logging levels

/// Sets the log level for a named event.
/// Equivalent to the public `setLogLevel:forEvent:` without compiler warnings.
- (BOOL)_connectSetLogLevel:(NSUInteger)logLevel forEvent:(NSString *)event;

/// Returns the log level for a named event.
/// Equivalent to the public `logLevelForEvent:` without compiler warnings.
- (NSUInteger)_connectLogLevelForEvent:(NSString *)event;

// MARK: – Layout config

/// Returns the AutoLayout configuration dictionary.
/// Equivalent to the public `layoutConfigItems` without compiler warnings.
- (nullable NSDictionary *)_connectLayoutConfigItems;

// MARK: – Device / identity

/// Sets the device identifier.
/// Equivalent to the public `setDeviceId:` without compiler warnings.
- (BOOL)_connectSetDeviceId:(NSString *)deviceId;

/// Returns the device identifier.
/// Equivalent to the public `getDeviceId` without compiler warnings.
- (nullable NSString *)_connectDeviceId;

/// Sets the CXA advertising identifier.
/// Equivalent to the public `setCXAAdvertisingId:` without compiler warnings.
- (BOOL)_connectSetCXAAdvertisingId:(NSString *)advertisingId;

/// Returns the CXA advertising identifier.
/// Equivalent to the public `getCXAAdvertisingId` without compiler warnings.
- (nullable NSString *)_connectCXAAdvertisingId;

/// Returns the current application context name.
/// Equivalent to the public `applicationContextName` without compiler warnings.
- (nullable NSString *)_connectApplicationContextName;

// MARK: – HTTP headers and cookies

/// Replaces the full set of additional HTTP headers.
/// Equivalent to the public `setAdditionalHttpHeaders:` without compiler warnings.
- (void)_connectSetAdditionalHTTPHeaders:(NSMutableDictionary *)headers;

/// Adds a single additional HTTP header.
/// Equivalent to the public `addAdditionalHttpHeader:forName:` without compiler warnings.
- (void)_connectAddAdditionalHTTPHeader:(NSString *)value forName:(NSString *)name;

/// Replaces the full set of additional HTTP cookies.
/// Equivalent to the public `setAdditionalHttpCookies:` without compiler warnings.
- (void)_connectSetAdditionalHTTPCookies:(NSMutableArray *)cookies;

/// Adds a single additional HTTP cookie.
/// Equivalent to the public `addAdditionalHttpCookie:` without compiler warnings.
- (void)_connectAddAdditionalHTTPCookie:(NSHTTPCookie *)cookie;

/// Returns the current additional HTTP headers dictionary.
/// Equivalent to the public `getAdditionalHttpHeaders` without compiler warnings.
- (nullable NSDictionary *)_connectAdditionalHTTPHeaders;

/// Returns the current additional HTTP cookies array.
/// Equivalent to the public `getAdditionalHttpCookies` without compiler warnings.
- (nullable NSArray *)_connectAdditionalHTTPCookies;

/// Attaches the Connect session cookie to a mutable URL request.
/// Equivalent to the public `sessionizeRequest:` without compiler warnings.
- (BOOL)_connectSessionizeRequest:(NSMutableURLRequest *)request;

// MARK: – WebView / UIApplication

/// Returns whether the given request is a Connect hybrid bridge request.
/// Equivalent to the public `isConnectHybridBridgeRequest:webView:` without compiler warnings.
- (BOOL)_connectIsHybridBridgeRequest:(NSURLRequest *)request webView:(id)webView;

/// Injects the Connect hybrid bridge JavaScript into the given web view.
/// Equivalent to the public `InjectConnectHybridBridgeOnWebViewDidFinishLoad:` without compiler warnings.
- (BOOL)_connectInjectHybridBridgeIntoWebView:(id)webView;

/// Forwards a UIEvent to the Connect framework.
/// Equivalent to the public `sendEvent:` without compiler warnings.
- (void)_connectSendEvent:(UIEvent *)event;

/// Forwards a UIAction to the Connect framework.
/// Equivalent to the public `sendAction:to:from:forEvent:` without compiler warnings.
- (void)_connectSendAction:(SEL)action
                        to:(nullable id)target
                      from:(nullable id)sender
                  forEvent:(nullable UIEvent *)event;

@end

NS_ASSUME_NONNULL_END
