#ifndef CIPHER_HPP
#define CIPHER_HPP

#include "CipherMode.hpp"
#include <string>


/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher virtual class
 */

class Cipher{
    public:

        //Basic resource management function that needs to be defined
        Cipher() = default;
        Cipher(const Cipher& rhs) = default;
        Cipher(Cipher&& rhs) = default;
        Cipher& operator = (const Cipher& rhs) = default;
        Cipher& operator=(Cipher&& rhs) = default;    
        virtual ~Cipher() = default;

        /**
         * \brief Apply the cipher to the provided text
         *
         * \param inputText the text to encrypt or decrypt
         * \param cipherMode whether to encrypt or decrypt the input text
         * \return the result of applying the cipher to the input text
         */
        virtual std::string applyCipher( const std::string& input, const CipherMode mode) const = 0;

}



