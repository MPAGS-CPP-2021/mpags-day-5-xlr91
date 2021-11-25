#ifndef CIPHERFACTORY_HPP
#define CIPHERFACTORY_HPP



#include "Cipher.hpp"
#include "CipherType.hpp"
#include <memory>


/**
     * \brief Generates a pointer for a specific cipher type and given key
     *
     * \param type Type of cipher Cipher::(Caesar, Playfair, Vigenere)
     * \param key key used to initialise the cipher
     */  
std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string& key);


#endif



