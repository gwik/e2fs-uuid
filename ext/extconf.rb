require 'mkmf'

have_library('uuid')
have_header('uuid/uuid.h') or fail('missing uuid/uuid.h header')
have_type('uuid_t', 'uuid/uuid.h') or fail('missing type uuid_t')
create_makefile('uuid_ext')
