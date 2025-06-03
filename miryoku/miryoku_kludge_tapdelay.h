// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

#pragma once

/*                                      42 KEY MATRIX / LAYOUT MAPPING

  ╭────────────────────────┬────────────────────────╮ ╭─────────────────────────┬─────────────────────────╮
  │  0   1   2   3   4   5 │  6   7   8   9  10  11 │ │ LT5 LT4 LT3 LT2 LT1 LT0 │ RT0 RT1 RT2 RT3 RT4 RT5 │
  │ 12  13  14  15  16  17 │ 18  19  20  21  22  23 │ │ LM5 LM4 LM3 LM2 LM1 LM0 │ RM0 RM1 RM2 RM3 RM4 RM5 │
  │ 24  25  26  27  28  29 │ 30  31  32  33  34  35 │ │ LB5 LB4 LB3 LB2 LB1 LB0 │ RB0 RB1 RB2 RB3 RB4 RB5 │
  ╰───────────╮ 36  37  38 │ 39  40  41 ╭───────────╯ ╰───────────╮ LH2 LH1 LH0 │ RH0 RH1 RH2 ╭───────────╯
              ╰────────────┴────────────╯                         ╰─────────────┴─────────────╯             */

#define KEYS_L 0 1 2 3 4 5 12 13 14 15 16 17 24 25 26 27 28 29
#define KEYS_R 6 7 8 9 10 11 18 19 20 21 22 23 30 31 32 33 34 35
#define THUMBS 36 37 38 39 40 41

#define MIRYOKU_TAPDELAY_TAP(CODE) \
U_MACRO(u_tapdelay_tap_##CODE, bindings = <&macro_press &kp CODE>, <&macro_release &kp CODE>;)


#define MIRYOKU_TAPDELAY_MTL(CODE) \
/ { \
  behaviors { \
    u_tapdelay_mtl_##CODE: u_tapdelay_mtl_##CODE { \
      compatible = "zmk,behavior-hold-tap"; \
      #binding-cells = <2>; \
      tapping-term-ms = <280>; \
      require-prior-idle-ms = <150>; \
      flavor = "balanced"; \
      hold-trigger-key-positions = <KEYS_R THUMBS>; \
      hold-trigger-on-release; \
      bindings = <&kp>, <&u_tapdelay_tap_##CODE>; \
    }; \
  }; \
};

#define MIRYOKU_TAPDELAY_MTR(CODE) \
/ { \
  behaviors { \
    u_tapdelay_mtr_##CODE: u_tapdelay_mtr_##CODE { \
      compatible = "zmk,behavior-hold-tap"; \
      #binding-cells = <2>; \
      tapping-term-ms = <280>; \
      require-prior-idle-ms = <150>; \
      flavor = "balanced"; \
      hold-trigger-key-positions = <KEYS_L THUMBS>; \
      hold-trigger-on-release; \
      bindings = <&kp>, <&u_tapdelay_tap_##CODE>; \
    }; \
  }; \
};

#define MIRYOKU_TAPDELAY_MT(CODE) \
/ { \
  behaviors { \
    u_tapdelay_mt_##CODE: u_tapdelay_mt_##CODE { \
      compatible = "zmk,behavior-hold-tap"; \
      #binding-cells = <2>; \
      tapping-term-ms = <U_TAPPING_TERM>; \
      flavor = "tap-preferred"; \
      bindings = <&kp>, <&u_tapdelay_tap_##CODE>; \
    }; \
  }; \
};

#define MIRYOKU_TAPDELAY_LT(CODE) \
/ { \
  behaviors { \
    u_tapdelay_lt_##CODE: u_tapdelay_lt_##CODE { \
      compatible = "zmk,behavior-hold-tap"; \
      #binding-cells = <2>; \
      tapping-term-ms = <U_TAPPING_TERM>; \
      flavor = "tap-preferred"; \
      bindings = <&mo>, <&u_tapdelay_tap_##CODE>; \
    }; \
  }; \
};

#define U_MTL(MOD, TAP) &u_tapdelay_mtl_##TAP MOD 0
#define U_MTR(MOD, TAP) &u_tapdelay_mtr_##TAP MOD 0
#define U_MT(MOD, TAP) &u_tapdelay_mt_##TAP MOD 0
#define U_LT(LAYER, TAP) &u_tapdelay_lt_##TAP LAYER 0

#define MIRYOKU_TAPDELAY_LIST \
MIRYOKU_X(A,) \
MIRYOKU_X(B,) \
MIRYOKU_X(C,) \
MIRYOKU_X(D,) \
MIRYOKU_X(E,) \
MIRYOKU_X(F,) \
MIRYOKU_X(G,) \
MIRYOKU_X(H,) \
MIRYOKU_X(I,) \
MIRYOKU_X(J,) \
MIRYOKU_X(K,) \
MIRYOKU_X(L,) \
MIRYOKU_X(M,) \
MIRYOKU_X(N,) \
MIRYOKU_X(O,) \
MIRYOKU_X(P,) \
MIRYOKU_X(Q,) \
MIRYOKU_X(R,) \
MIRYOKU_X(S,) \
MIRYOKU_X(T,) \
MIRYOKU_X(U,) \
MIRYOKU_X(V,) \
MIRYOKU_X(W,) \
MIRYOKU_X(X,) \
MIRYOKU_X(Y,) \
MIRYOKU_X(Z,) \
MIRYOKU_X(SQT,) \
MIRYOKU_X(COMMA,) \
MIRYOKU_X(DOT,) \
MIRYOKU_X(SLASH,) \
MIRYOKU_X(ESC,) \
MIRYOKU_X(SPACE,) \
MIRYOKU_X(TAB,) \
MIRYOKU_X(RET,) \
MIRYOKU_X(BSPC,) \
MIRYOKU_X(DEL,)
