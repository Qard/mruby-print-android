#include "mruby.h"
#include "mruby/string.h"
#include <android/log.h>

static void
android_printstr(mrb_state *mrb, mrb_value obj)
{
  struct RString *str;

  if (mrb_string_p(obj)) {
    __android_log_write(ANDROID_LOG_INFO, "MRuby", RSTRING_PTR(obj));
  }
}

/* 15.3.1.2.9  */
/* 15.3.1.3.34 */
mrb_value
mrb_android_printstr(mrb_state *mrb, mrb_value self)
{
  mrb_value argv;

  mrb_get_args(mrb, "o", &argv);
  android_printstr(mrb, argv);

  return argv;
}

void
mrb_mruby_print_android_gem_init(mrb_state* mrb)
{
  struct RClass *krn;
  krn = mrb->kernel_module;
  mrb_define_method(mrb, krn, "__printstr__", mrb_android_printstr, MRB_ARGS_REQ(1));
}

void
mrb_mruby_print_android_gem_final(mrb_state* mrb)
{
}
