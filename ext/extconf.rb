require 'mkmf'

if find_header('uuid/uuid.h')
  create_makefile('UUID')
else

  STDERR.puts 'missing uuid'
  exit(1)

end