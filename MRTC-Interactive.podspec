Pod::Spec.new do |s|
  s.name = "MRTC-Interactive"
  s.version = "1.0.0"
  s.summary = "A video conference SDK depends on MRTC"
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"张志超"=>"zhangzhichao@mudu.tv"}
  s.homepage = "https://www.muducloud.com"
  s.description = "TODO: Add long description of the pod here"
  s.source = { :git => '', :tag => s.version.to_s}

  s.ios.deploment_target 	= '9.0'
  s.ios.vendored_framework	= 'ios/MRTC-Interactive.framework'

  s.dependency = 'MRTC','>=1.1.2'

 end
