#include <uuid/uuid.h>
#include "ruby.h"

static uuid2ary(uuid_t uuid)
{
  int i;
  volatile VALUE ary = rb_ary_new();
  
  for(i=0; i < 16; i++)
    rb_ary_push(ary, INT2FIX(uuid[i]));
  
  return ary;
}

static uuid2str(uuid_t uuid)
{
  char * out = malloc(sizeof(char) * 37);
  uuid_unparse(uuid, out);
  return rb_str_new2(out);
}

static VALUE uuid_to_rb(uuid_t uuid, VALUE raw)
{
  if (RTEST(raw))
    return uuid2ary(uuid);
  return uuid2str(uuid);
}

static VALUE UUID_generate(VALUE self)
{
  int i;
  uuid_t out;
  
  uuid_generate(out);
  
  return uuid2ary(out);
}

static VALUE UUID_generate_time(VALUE self)
{
  int i;
  uuid_t out;
  
  uuid_generate_time(out);
  
  return uuid2ary(out);
}

static VALUE UUID_generate_random(VALUE self)
{
  int i;
  uuid_t out;
  
  uuid_generate_random(out);
  
  return uuid2ary(out);
}

void Init_uuid_ext()
{
  VALUE rb_mE2FS = rb_define_module("E2FS");
  VALUE rb_cUUID = rb_define_class_under(rb_mE2FS, "UUID", rb_cObject);
  rb_define_const(rb_mE2FS, "VERSION", rb_str_new2("0.1.0"));
  rb_define_singleton_method(rb_cUUID, "generate", UUID_generate, 0);
  rb_define_singleton_method(rb_cUUID, "generate_time", UUID_generate_time, 0);
  rb_define_singleton_method(rb_cUUID, "generate_random", UUID_generate_random, 0);
}
