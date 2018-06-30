# simple encryption library
Standard Simple Modern Cryptography Library
-User Facing Primitives Library and Binary

In an attempt to make cryptography simple to get right, a series of small, simple libraries have been created lately

libnacl
libsodium
tweetnacl
libmonocypher

And others.   

These all share a common set of cryptography primitives, with some limited exceptions.  sel is an attempt to unify them all into a commmon cryptography toolset that supports exactly the set of primitives required.

In addition, these libraries do not allow a standard user-facing standard for such important tasks as key management, keyring management, key derivation, and human readable or ascii serialization of ciphertexts, signatures, and keys to allow

sel aims to solve these two problems in three respects:  

First, sel provides a common interface for multiple 'simple' crypto libraries that optionally provides the base features.  You can switch between them based on performance and compatibility.  The sel core interface can also be reimplemented in other languages

Second, sel provides an implementation and a standard for all user-facing primitives such as key serialization and derivation.

Finally, sel provides the unified definitions of which crypto primitives are to be used.

Sel has multiple "profiles" for different optional configurations, as well as extendibility.

