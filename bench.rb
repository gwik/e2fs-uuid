require 'rubygems'
require 'uuid'
require File.dirname(__FILE__) + '/lib/e2fs-uuid'
require 'benchmark'

N = 1000

puts "Generating #{N} uuid"

res = Benchmark.bm do |b|
  b.report("e2fs-uuid gen string"){ N.times { E2FS::UUID.generate_string } }
  b.report("assaf-uuid gen string"){ N.times { UUID.generate }  }
  puts "--"
  b.report("e2fs-uuid new.to_s") { N.times { E2FS::UUID.new.to_s } }
  b.report("assaf-uuid new.to_s") { N.times { UUID.new.to_s } }
end
