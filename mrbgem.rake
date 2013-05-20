MRuby::Gem::Specification.new('mruby-print-android') do |spec|
  spec.license = 'MIT'
  spec.authors = 'Stephen Belanger'
  spec.linker.libraries << ['log']
	spec.linker.flags << '-L/usr/local/opt/android-ndk/platforms/android-8/arch-arm/usr/lib'
end
