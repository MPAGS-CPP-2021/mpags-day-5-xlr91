#ifndef MPAGSCIPHER_VIGENERE_HPP
#define MPAGSCIPHER_VIGENERE_HPP

#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "Cipher.hpp"
#include <string>
#include <map>

/**
 * \file VigenereCipher.hpp
 * \brief Contains the declaration of the VigenereCipher class
 */

/**
 * \class VigenereCipher
 * \brief Encrypt or decrypt text using the Vigenere cipher with the given key
 */


class VigenereCipher : public Cipher {
  public:
    /**
     * \brief Create a new PlayfairCipher with the given key
     *
     * \param key the key to use in the cipher
     */
    explicit VigenereCipher(const std::string& key);

    /**
     * \brief Set the key to be used for the encryption/decryption
     *
     * \param key the key to use in the cipher
     */
    void setKey(const std::string& key);


    virtual std::string applyCipher(const std::string& input,
                                    const CipherMode mode) const override;

    /**
     * \brief Returns the key of the cipher
     */

    std::string returnKey() const;


  private:

    /// The cipher key
    std::string key_{""};

    /// LookupTable
    std::map<char, CaesarCipher> charLookup_;
};

#endif