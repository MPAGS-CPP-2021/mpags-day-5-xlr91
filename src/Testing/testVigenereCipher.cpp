//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"




TEST_CASE("Exists", "[playfair]") {
    REQUIRE(true);
}


TEST_CASE("Vigenere Cipher set key", "[vigenere]") {
    VigenereCipher vc{"hello"};
    std::string output = "HELLO";
    REQUIRE(vc.returnKey() == output);
}


TEST_CASE("Vigenere Cipher set empty", "[vigenere]") {
    VigenereCipher vc{""};
    std::string output = "KEY";
    REQUIRE(vc.returnKey() == output);
}

TEST_CASE("VigenerCipher Cipher encryption", "[vigenere]") {
  VigenereCipher vc{"KEY"};
  REQUIRE( vc.applyCipher("HELLOWORLD", CipherMode::Encrypt) == "RIJVSUYVJN");
}

/*
TEST_CASE("VigenerCipher Cipher encryption", "[playfair]") {
  VigenerCipher cc{"hello"};
  REQUIRE( cc.applyCipher("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", CipherMode::Encrypt) == "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
}

TEST_CASE("VigenerCipher Cipher decryption", "[playfair]") {
  VigenerCipher cc{"hello"};
  REQUIRE( cc.applyCipher("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", CipherMode::Decrypt) == "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ");
}


*/