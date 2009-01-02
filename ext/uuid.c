#include <uuid/uuid.h>
#include "ruby.h"

static VALUE rb_mUUID;

static VALUE uuid_to_rbstr(uuid_t uuid)
{
  char * out = malloc(sizeof(char) * 37);
  uuid_unparse(uuid, out);
  return rb_str_new2(out);
}

static VALUE UUID_generate()
{
  int i;
  uuid_t out;
  
  uuid_generate(out);
  
  return uuid_to_rbstr(out);
}

static VALUE UUID_generate_time()
{
  int i;
  uuid_t out;
  
  uuid_generate_time(out);
  
  return uuid_to_rbstr(out);
}

static VALUE UUID_generate_random()
{
  int i;
  uuid_t out;
  
  uuid_generate_random(out);
  
  return uuid_to_rbstr(out);
}

void Init_UUID()
{
  rb_mUUID = rb_define_module("UUID");
  rb_define_const(rb_mUUID, "VERSION", rb_str_new2("0.1.0"));
  rb_define_singleton_method(rb_mUUID, "generate", UUID_generate, 0);
  rb_define_singleton_method(rb_mUUID, "generate_time", UUID_generate_time, 0);
  rb_define_singleton_method(rb_mUUID, "generate_random", UUID_generate_random, 0);
}
