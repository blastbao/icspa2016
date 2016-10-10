#include "prefix/prefix.h"

#include "data-mov/mov.h"
#include "data-mov/xchg.h"
#include "data-mov/movsx.h"
#include "data-mov/movzx.h"
#include "data-mov/cwd.h"

#include "control/call.h"
#include "control/push.h"
#include "control/pop.h"
#include "control/ret.h"
#include "control/leave.h"
#include "control/ja.h"
#include "control/jae.h"
#include "control/jb.h"
#include "control/jbe.h"
#include "control/jecxz.h"
#include "control/jg.h"
#include "control/jge.h"
#include "control/jl.h"
#include "control/jle.h"
#include "control/jno.h"
#include "control/jnp.h"
#include "control/jns.h"
#include "control/jnz.h"
#include "control/jo.h"
#include "control/jp.h"
#include "control/js.h"
#include "control/jz.h"
#include "control/jmp.h"

#include "arith/add.h"
#include "arith/adc.h"
#include "arith/sub.h"
#include "arith/sbb.h"
#include "arith/dec.h"
#include "arith/inc.h"
#include "arith/neg.h"
#include "arith/imul.h"
#include "arith/mul.h"
#include "arith/idiv.h"
#include "arith/div.h"

#include "logic/and.h"
#include "logic/or.h"
#include "logic/not.h"
#include "logic/xor.h"
#include "logic/sar.h"
#include "logic/shl.h"
#include "logic/shr.h"
#include "logic/shrd.h"
#include "logic/test.h"
#include "logic/cmp.h"
#include "logic/seta.h"
#include "logic/setae.h"
#include "logic/setb.h"
#include "logic/setbe.h"
#include "logic/setg.h"
#include "logic/setge.h"
#include "logic/setl.h"
#include "logic/setle.h"
#include "logic/setno.h"
#include "logic/setnp.h"
#include "logic/setns.h"
#include "logic/setnz.h"
#include "logic/seto.h"
#include "logic/setp.h"
#include "logic/sets.h"
#include "logic/setz.h"

#include "string/rep.h"

#include "misc/misc.h"

#include "special/special.h"
