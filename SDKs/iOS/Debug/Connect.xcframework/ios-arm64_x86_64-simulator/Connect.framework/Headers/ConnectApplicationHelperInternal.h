//
// Copyright (C) 2026 Acoustic, L.P. All rights reserved.
//
// NOTICE: This file contains material that is confidential and proprietary to
// Acoustic, L.P. and/or other developers. No license is granted under any
// intellectual or industrial property rights of Acoustic, L.P. except as may
// be provided in an agreement with Acoustic, L.P. Any unauthorized copying or
// distribution of content from this file is prohibited.
//

#import "ConnectApplicationHelper.h"

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
@interface ConnectApplicationHelper (Internal)

/// Enables the framework with explicit credentials.
/// Equivalent to the public `enableFramework:withPostMessageUrl:` without deprecation.
- (BOOL)_connectEnableWithAppKey:(NSString *)appKey postURL:(NSString *)postURL;

/// Disables the framework.
/// Equivalent to the public `disableFramework` without deprecation.
- (BOOL)_connectDisable;

/// Returns whether the framework is currently enabled.
/// Equivalent to the public `isTLFEnabled` without deprecation.
- (BOOL)_connectIsEnabled;

/// Returns the Connect framework version string.
/// Equivalent to the public `frameworkVersion` without deprecation.
- (NSString *)_connectFrameworkVersion;

@end
