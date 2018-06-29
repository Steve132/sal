# sod
Standard Simple Modern Cryptography User Facing Primitives

In an attempt to make cryptography simple to get right, a series of small, simple libraries have been created.

#hala

libnacl
libsodium
tweetnacl
libmonocypher

And others. 

These all share a common set of cryptography primitives, with some limited exceptions.  sod is an attempt to unify them all into a commmon cryptography toolset that supports exactly the set of primitives required.

In addition, these libraries do not allow a standard user-facing standard for such important tasks as key management, keyring management, key derivation, and human readable or ascii serialization of ciphertexts, signatures, and keys to allow

sod aims to solve these two problems in three respects:  

First, sod provides a common interface for all 4 implementations that optionally provides all features.
Second, sod provides an implementation and a standard for all user-facing tasks.
Finally, sod provides the unified definitions of which crypto primitives are to be used.

Sod has multiple "profiles" for different optional configurations, as well as extendibility.

