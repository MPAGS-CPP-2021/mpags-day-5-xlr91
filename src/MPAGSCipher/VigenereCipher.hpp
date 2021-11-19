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
    

    /*
    /// The grid size
    const std::string::size_type gridSize_{5};

    /// The key length = grid size^2
    const std::string::size_type keyLength_{gridSize_ * gridSize_};

    

    // Lookup tables generated from the key

    /// Type definition for the coordinates in the 5x5 table
    using PlayfairCoords = std::pair<std::size_t, std::size_t>;

    /// Lookup table to go from the character to the coordinates
    std::map<char, PlayfairCoords> charLookup_;

    /// Lookup table to go from the coordinates to the character
    std::map<PlayfairCoords, char> coordLookup_;

    */
};

#endif