Gem::Specification.new do |spec|
  spec.name = 'e2fs-uuid'
  spec.version = '0.1.0'
  spec.summary = 'Ruby C bindings to e2fs uuid library'
  spec.author = "Antonin Amand"
  spec.email = 'antonin.amand@gmail.com'
  spec.files = Dir['ext/*.c', 'lib/*.rb']
  spec.homepage = 'http://github.com/gwik/e2fs-uuid'
  spec.has_rdoc = false
  spec.extensions << 'ext/extconf.rb'
  spec.require_path = 'lib'
  spec.date = Time.now
  spec.requirements << 'uuid/uuid.h'
end
