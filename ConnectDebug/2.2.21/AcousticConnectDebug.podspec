
Pod::Spec.new do |s|
  s.name = 'AcousticConnectDebug'
  s.version = '2.2.21'
  s.author = 'Acoustic, L.P.'
  s.license = { :type => 'Proprietary, Acoustic, L.P.', :text => 'https://github.com/go-acoustic/Connect/blob/master/Licenses/License' }
  s.homepage = 'https://github.com/go-acoustic/Connect'
  s.summary = 'Acoustic Connect iOS SDK. Install with SPM (go-acoustic/Connect-SP) or CocoaPods via go-acoustic/PodSpecs.'
  s.description = <<-DESC
Acoustic Connect iOS SDK.

Swift Package Manager is the recommended integration:
https://github.com/go-acoustic/Connect-SP (release) or https://github.com/go-acoustic/ConnectDebug-SP (debug).

For CocoaPods, add the Acoustic spec repo above the CocoaPods CDN in your Podfile:
  source 'https://github.com/go-acoustic/PodSpecs.git'
  source 'https://cdn.cocoapods.org/'

CocoaPods trunk becomes read-only on 2 December 2026 and receives no later versions of this pod.
  DESC
  s.cocoapods_version = '>= 1.10.0'
  s.platforms = { :ios => '15.1' }
  s.source = { :git => 'https://github.com/go-acoustic/Connect.git', :tag => '2.2.21'}
  s.default_subspec = 'Core'
  s.subspec 'Core' do |core|
    core.frameworks = 'SystemConfiguration', 'CoreTelephony', 'CoreLocation', 'WebKit'
    core.library = 'z'
    core.resource = "SDKs/iOS/Debug/ConnectResources.bundle"
    core.xcconfig = { 'HEADER_SEARCH_PATHS' => '"$(PODS_ROOT)/SDKs/iOS/Debug/Connect.xcframework/*/Connect.framework/Headers/"/** ' }
    core.vendored_frameworks = 'SDKs/iOS/Debug/Connect.xcframework', 'SDKs/iOS/Debug/Tealeaf.xcframework', 'SDKs/iOS/Debug/EOCore.xcframework'
  end
end