//
// Copyright (C) 2024 Acoustic, L.P. All rights reserved.
//
// NOTICE: This file contains material that is confidential and proprietary to
// Acoustic, L.P. and/or other developers. No license is granted under any intellectual or
// industrial property rights of Acoustic, L.P. except as may be provided in an agreement with
// Acoustic, L.P. Any unauthorized copying or distribution of content from this file is
// prohibited.
//
//  ConnectPublicDefinitions.h
//  Connect
//
//  Created by Omar Hernandez on 4/29/24.
//

#import <UIKit/UIKit.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <Foundation/Foundation.h>
//#import "Tealeaf/ConnectPublicDefinitions.h"

// Version
#define CONNECT_FRAMEWORK_VER @"1.0.30" //ReleaseVersion.SprintVersion.MinorVersion
#define kConnectCoreModule                              @"ConnectCoreModule"
//#define kConfigurableItemEventLevels                    @"EventLevels"
//#define kConfigurableItemTreatJsonDictionariesAsString  @"TreatJsonDictionariesAsString"
//
//#define kItemLogLevels @"ItemLogLevels"
//
typedef NS_ENUM(NSUInteger, ConnectScreenViewType) {
    ConnectScreenViewTypeVisit = 3,
    ConnectScreenViewTypeLoad = 2,
    ConnectScreenViewTypeUnload = 1,
    ConnectScreenViewTypeNil = 0
};

//Enums
#ifndef NS_ENUM
#import <Foundation/Foundation.h>
#endif
typedef NS_ENUM(int, kConnectMonitoringLevelType) {
    kConnectMonitoringLevelIgnore = 0,
    kConnectMonitoringLevelCellularAndWiFi = 1,
    kConnectMonitoringLevelWiFi = 2,
};

typedef NS_ENUM(int, ConnectPerformanceNavigationType) {
    ConnectNavigate = 0,
    ConnectReload = 1,
    ConnectBack_Forward = 2,
    ConnectReserved = 255,
};

extern NSString* kConnectButtonClickEvent;
extern NSString* kConnectToggleButtonClickEvent;
extern NSString* kConnectSliderValueChangeEvent;
extern NSString* kConnectStepperValueChangeEvent;
extern NSString* kConnectSelectListValueChangeEvent;
extern NSString* kConnectDatePickerDateChangeEvent;
extern NSString* kConnectTextBoxTextChangeEvent;
extern NSString* kConnectScrollerScrollChangeEvent;
extern NSString* kConnectActionSheetButtonIndexEvent;
extern NSString* kConnectActionSheetShowEvent;
extern NSString* kConnectAlertviewButtonIndexEvent;
extern NSString* kConnectAlertViewShowEvent;
extern NSString* kConnectPrintscreenEvent;
extern NSString* kConnectCustomEventEvent;
extern NSString* kConnectExceptionEvent;
extern NSString* kConnectConnectionEvent;
extern NSString* kConnectMobileStateEvent;

//// The configurable items, needs to match with keys of "ConnectResources.bundle/ConnectConfigurableItems.plist" file.
//#define kConfigurableItemCachingLevel                                       @"CachingLevel"
//#define kConfigurableItemCachedFileMaxBytesSize                             @"CachedFileMaxBytesSize"
//#define kConfigurableItemHasToPersistLocalCache                             @"HasToPersistLocalCache"
//#define kConfigurableItemPostMessageLevelWifi                               @"PostMessageLevelWiFi"
//#define kConfigurableItemPostMessageLevelCellular                           @"PostMessageLevelCellular"
//#define kConfigurableItemPostMessageUrl                                     @"PostMessageUrl"
//#define kConfigurableItemPostMessageTimeIntervals                           @"PostMessageTimeIntervals"
//#define kConfigurableItemPostMessageMaxBytesSize                            @"PostMessageMaxBytesSize"
//#define kConfigurableItemPostMessageSecondLevel                             @"PostMessageSecondLevel"
//#define kConfigurableItemDoPostOnIntervals                                  @"DoPostOnIntervals"
//#define kConfigurableItemDoPostAppIsLaunched                                @"DoPostAppIsLaunched"
//#define kConfigurableItemDoPostAppGoesToBackground                          @"DoPostAppGoesToBackground"
//#define kConfigurableItemDoPostAppGoesToClose                               @"DoPostAppGoesToClose"
//#define kConfigurableItemDoPostAppComesFromBackground                       @"DoPostAppComesFromBackground"
//#define kConfigurableItemKillSwitchEnabled                                  @"KillSwitchEnabled"
//#define kConfigurableItemKillSwitchUrl                                      @"KillSwitchUrl"
//#define kConfigurableItemKillSwitchTimeout                                  @"KillSwitchTimeout"
//#define kConfigurableItemKillSwitchMaxNumberOfTries                         @"KillSwitchMaxNumberOfTries"
//#define kConfigurableItemKillSwitchTimeInterval                             @"KillSwitchTimeInterval"
//#define kConfigurableItemUseWhiteList                                       @"UseWhiteList"
//#define kConfigurableItemWhiteListParam                                     @"WhiteListParam"
//#define kConfigurableItemManualPostEnabled                                  @"ManualPostEnabled"
//#define kConfigurableItemDoPostOnScreenChange                               @"DoPostOnScreenChange"
//#define kConfigurableItemPostMessageTimeout                                 @"PostMessageTimeout"
//#define kConfigurableItemMaxStringsLength                                   @"MaxStringsLength"
//#define kConfigurableItemDisableAutoInstrumentation                         @"DisableAutoInstrumentation"
//#define kConfigurableItemCompressPostMessage                                @"CompressPostMessage"
//#define kConfigurableItemPercentOfScreenshotsSize                           @"PercentOfScreenshotsSize"
//#define kConfigurableItemScreenShotPixelDensity                             @"ScreenShotPixelDensity"
//#define kConfigurableItemDisableConnectFrameworkFlush                           @"DisableConnectFrameworkFlush"
//#define kConfigurableItemScreenshotFormat                                   @"ScreenshotFormat"
//#define kConfigurableItemJavaScriptInjectionDelay                           @"JavaScriptInjectionDelay"
//#define kConfigurableItemFilterMessageTypes                                 @"FilterMessageTypes"
//#define kConfigurableItemMessageTypesToBeFiltered                           @"MessageTypes"
//#define kConfigurableItemSessionTimeout                                     @"SessionTimeout"
//#define kConfigurableItemAddMessageTypeHeader                               @"AddMessageTypeHeader"
//#define kConfigurableItemMessageTypeHeader                                  @"MessageTypeHeader"
//#define kConfigurableItemGetImageDataOnScreenLayout                         @"GetImageDataOnScreenLayout"
//#define kConfigurableItemSessionizationCookieName                           @"SessionizationCookieName"
//#define kConfigurableItemSessionizationCookieSecure                         @"CookieSecure"
//#define kConfigurableItemSetGestureDetector                                 @"SetGestureDetector"
//#define kConfigurableItemLogLocationEnabled                                 @"LogLocationEnabled"
//#define kConfigurableItemSaasAppKey                                         @"AppKey"
//#define kConfigurableItemAppendMapIDs                                       @"AppendMapIds"
//#define kConfigurableItemAutoLayout                                         @"AutoLayout"
//#define kConfigurableItemRemoveIp                                           @"RemoveIp"
//#define kConfigurableItemIpPlaceholder                                      @"IpPlaceholder"
//#define kConfigurableItemUseJPGForReplayImagesExtension                     @"UseJPGForReplayImagesExtension"
//#define kConfigurableItemDisableKeyboardCapture                             @"DisableKeyboardCapture"
//#define kConfigurableItemEnableWebViewInjectionForDisabledAutoCapture       @"EnableWebViewInjectionForDisabledAutoCapture"
//#define kConfigurableItemDisableAlertAutoCapture                            @"DisableAlertAutoCapture"
//#define kConfigurableItemDisableAlertBackgroundForDisabledLogViewLayout     @"DisableAlertBackgroundForDisabledLogViewLayout"
//#define kConfigurableItemInitialZIndex                                      @"InitialZIndex"
//#define kConfigurableItemSubViewArrayZIndexIncrementTrigger                 @"SubViewArrayZIndexIncrementTrigger"
//#define kConfigurableItemUseXpathId                                         @"UseXpathId"
//#define kConfigurableItemAddGestureRecognizerUIScrollView                   @"AddGestureRecognizerUIScrollView"
//#define kConfigurableItemAddGestureRecognizerUITextView                     @"AddGestureRecognizerUITextView"
//#define kConfigurableItemAddGestureRecognizerUIButton                       @"AddGestureRecognizerUIButton"
//#define kConfigurableItemAddGestureRecognizerUISwitch                       @"AddGestureRecognizerUISwitch"
//#define kConfigurableItemAddGestureRecognizerUISegmentedControl             @"AddGestureRecognizerUISegmentedControl"
//#define kConfigurableItemAddGestureRecognizerUIPickerView                   @"AddGestureRecognizerUIPickerView"
//#define kConfigurableItemAddGestureRecognizerUIDatePicker                   @"AddGestureRecognizerUIDatePicker"
//#define kConfigurableItemAddGestureRecognizerUIPageControl                  @"AddGestureRecognizerUIPageControl"
//#define kConfigurableItemAddGestureRecognizerWKWebView                      @"AddGestureRecognizerWKWebView"
//#define kConfigurableItemSwiftUICaptureNonVariadic                          @"SwiftUICaptureNonVariadic"
//#define kConfigurableItemUIKeyboardCaptureTouches                           @"UIKeyboardCaptureTouches"
//#define kConfigurableItemTextFieldBeingEditedUseSender                      @"TextFieldBeingEditedUseSender"
//#define kConfigurableItemRemoveSwiftUIDuplicates                            @"RemoveSwiftUIDuplicates"
//#define kConfigurableItemLogFullRequestResponsePayloads                     @"LogFullRequestResponsePayloads"
//#define kConfigurableItemLogViewLayoutOnScreenTransition                    @"LogViewLayoutOnScreenTransition"
//#define kConfigurableItemDisableTLTDID                                      @"disableTLTDID"
//
//// Connect Public Protocols
//@protocol ConnectSavePrintScreenOperationDelegate <NSObject>
//@optional
//- (void)savePrintScreenOnTemporaryDirectoryOperationDidFinishSuccessfullyWithImageName:(NSString*)imageName;
//
//@end
//@protocol ConnectLibDelegate <NSObject>
//@optional
///**
// After set a delegate to your ConnectApplication implement this callback to generate your custom Session ID
// */
//- (NSString*)sessionIdGeneration;
//
//@end
//@protocol ConnectApplicationHelperJSProtocol <JSExport>
//- (BOOL)enableTealeafFramework;
//- (void)disableTealeafFramework;
//- (void)requestManualServerPost;
//- (BOOL)startNewConnectSession;
//- (NSString*)currentSessionId;
//- (BOOL)setConfigurableItem:(NSString*)configItem value:(id)value;
//- (id)valueForConfigurableItem:(NSString*)configItem;
//- (id)defaultValueForConfigurableItem:(NSString*)configItem;
//- (void)addAdditionalHttpHeader:(NSString*)value forName:(NSString*)name;
//@end
//@protocol ConnectCustomControlDelegate <NSObject>
//@optional
//- (BOOL)isConnectCustomControlHidden;
//- (NSInteger)tagConnectCustomControl;
//- (id)parentConnectCustomControl;
//- (CGRect)frameConnectCustomControl;
//- (UIColor*)colorConnectCustomControl;
//- (UIColor*)backgroundColorConnectCustomControl;
//
//- (NSString*)textConnectCustomControl;
//- (BOOL)isConnectCustomControlTextHidden;
//- (CGRect)textFrameConnectCustomControl;
//- (UIColor*)textConnectCustomControlColor;
//- (UIColor*)textConnectCustomControlBackgroundColor;
//
//- (UIImage*)imageConnectCustomControl;
//- (BOOL)isConnectCustomControlImageHidden;
//- (CGRect)imageFrameConnectCustomControl;
//- (UIColor*)imageOpacityConnectCustomControl;
//- (UIColor*)imageBackgroundColorConnectCustomControl;
//@end
//
//@protocol ConnectCustomControlDelegateX <NSObject>
//@optional
//- (NSArray*) imageViewsConnectCustomControl;
//- (NSArray*) controlsConnectCustomControl;
//@end
//
//@protocol ConnectCustomEventJSProtocol <JSExport>
//- (BOOL)logEvent:(NSString*)eventName;
//- (BOOL)logEvent:(NSString*)eventName values:(NSDictionary*)values;
//- (BOOL)logPrintScreenEvent;
//- (BOOL)logJSONMessagePayloadStr:(NSString*)payload;
//@end
//
