#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CipherFactory.hpp"
#include <map>
#include <vector>
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"



bool testCipher(const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText){

    return (cipher.applyCipher(inputText, mode) == outputText);
}







TEST_CASE("full cipher test encryption", "[all]"){

  std::vector<std::unique_ptr<Cipher>> cipherInventory;
  cipherInventory.push_back(cipherFactory(CipherType::Caesar, "10"));
  cipherInventory.push_back(cipherFactory(CipherType::Playfair, "hello"));
  cipherInventory.push_back(cipherFactory(CipherType::Vigenere, "KEY"));

  std::vector<std::string> plaintext;
  plaintext.push_back("HELLO");
  plaintext.push_back("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING");
  plaintext.push_back("HELLOWORLD");

  std::vector<std::string> ciphertext;
  ciphertext.push_back("ROVVY");
  ciphertext.push_back("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
  ciphertext.push_back("RIJVSUYVJN");

  for(std::vector<int>::size_type i = 0; i < plaintext.size(); ++i){
    REQUIRE(cipherInventory.at(i) -> applyCipher(plaintext.at(i), CipherMode::Encrypt) == ciphertext.at(i));
  }
}


//could use maps similarly to what was shown on the solutions
TEST_CASE("Caesar Cipher encryption", "[caesar]")
{
    CaesarCipher cc{10};
    std::string input = "HELLOWORLD";
    std::string output = "ROVVYGYBVN";

    REQUIRE(testCipher(cc, CipherMode::Encrypt, input, output));    
}

TEST_CASE("Caesar Cipher decryption", "[caesar]")
{
    
    CaesarCipher cc{10};
    std::string input = "ROVVYGYBVN";
    std::string output = "HELLOWORLD";

    REQUIRE(testCipher(cc, CipherMode::Decrypt, input, output));    
}



TEST_CASE("Playfair Cipher encryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  std::string input = "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING";
  std::string output = "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA";

  REQUIRE(testCipher(cc, CipherMode::Encrypt, input, output));
}


TEST_CASE("Playfair Cipher decryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  std::string input = "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA";
  std::string output = "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ";

  REQUIRE(testCipher(cc, CipherMode::Decrypt, input, output));
}


TEST_CASE("VigenerCipher Cipher encryption", "[vigenere]") {
  VigenereCipher vc{"KEY"};
  std::string input = "HELLOWORLD";
  std::string output = "RIJVSUYVJN";

  REQUIRE(testCipher(vc, CipherMode::Encrypt, input, output));
}


TEST_CASE("VigenerCipher Cipher decryption", "[vigenere]") {
  VigenereCipher vc{"KEY"};
  std::string input = "RIJVSUYVJN";
  std::string output = "HELLOWORLD";

  REQUIRE(testCipher(vc, CipherMode::Decrypt, input, output));
}