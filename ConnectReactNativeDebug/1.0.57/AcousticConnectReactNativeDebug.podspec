
Pod::Spec.new do |s|
  s.name = 'AcousticConnectReactNativeDebug'
  s.version = '1.0.57'
  s.author = 'Acoustic, L.P.'
  s.license = { :type => 'Proprietary, Acoustic, L.P.', :text => 'https://github.com/go-acoustic/Connect/blob/master/Licenses/License' }
  s.homepage = 'https://github.com/go-acoustic/Connect'
  s.summary = 'Acoustic Connect Tealeaf EOCore iOS SDK React Native'
  s.cocoapods_version = '>= 1.10.0'
  s.platforms = { :ios => '12.0' }
  s.source = { :git => 'https://github.com/go-acoustic/Connect.git', :tag => '1.0.57'}
  s.default_subspec = 'Core'
  s.subspec 'Core' do |core|
    core.frameworks = 'SystemConfiguration', 'CoreTelephony', 'CoreLocation', 'WebKit'
    core.library = 'z'
    core.resource = "SDKs/iOS/DebugConnectReactNative/ConnectResources.bundle"
    core.xcconfig = { 'HEADER_SEARCH_PATHS' => '"$(PODS_ROOT)/SDKs/iOS/DebugConnectReactNative.xcframework/*/ConnectReactNative.framework/Headers/"/**' }
    core.vendored_frameworks = 'SDKs/iOS/DebugConnectReactNative/ConnectReactNative.xcframework'
    core.dependency 'TealeafReactNativeDebug'
  end
end