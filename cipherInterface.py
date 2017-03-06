#!/usr/bin/env python

class CipherInterface:
    def __init__(self, key):
        self.set_key(key)
    def set_key(self, key):
        self.key = key
    def encrypt(self, plaintext):
        pass
    def decrypt(self, ciphertext):
        pass