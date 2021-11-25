#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"




std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string& key){
    
    switch (type) {
        case CipherType::Caesar: {
            // Run the Caesar cipher (using the specified key and encrypt/decrypt flag) on the input text
            return std::make_unique<CaesarCipher>(key);
            break;
        }
        case CipherType::Playfair: {
            return std::make_unique<PlayfairCipher>(key);
            break;
        }

        case CipherType::Vigenere: {
            return std::make_unique<VigenereCipher>(key);
            break;
        }
    }

    return std::unique_ptr<Cipher>{};
    
}

