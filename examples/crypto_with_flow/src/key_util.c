//@ #include "../annotated_api/general_definitions/key_util.gh"
//@ #include "../annotated_api/general_definitions/public_chars.gh"

/*@

#define GENERAL_INTERPRET_METHOD(KIND) \
lemma void interpret_##KIND##_key(char *buffer, int size, list<char> cs) \
  requires [_]public_invar(?pub) &*& \
           [?f]chars(buffer, size, cs); \
  ensures  [f]cryptogram(buffer, size, cs, ?cg) &*& [_]pub(cg) &*& \
           cg == cg_##KIND##_key(?p, ?c); \
{ \
  cryptogram key = chars_for_cg_sur_##KIND##_key(cs); \
  public_chars_extract(buffer, key); \
  assert key == cg_##KIND##_key(?p, ?c); \
  public_chars(buffer, size, cs); \
  open [_]public_generated(pub)(cs); \
  if (!collision_in_run) \
  { \
    crypto_chars(buffer, size, cs); \
    forall_mem(key, cgs_in_chars(cs), cg_is_generated); \
  } \
  close [f]cryptogram(buffer, size, cs, key); \
}

GENERAL_INTERPRET_METHOD(symmetric)

GENERAL_INTERPRET_METHOD(public)

GENERAL_INTERPRET_METHOD(private)

@*/