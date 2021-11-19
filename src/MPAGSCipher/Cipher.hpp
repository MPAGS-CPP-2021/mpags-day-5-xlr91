#ifndef CIPHER_HPP
#define CIPHER_HPP

#include "CipherMode.hpp"
#include <string>

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher virtual class
 */

class Cipher {
  public:
    //Basic resource management function that needs to be defined
    Cipher() = default;
    /**
     * \brief Copy constructor
     */
    Cipher(const Cipher& rhs) = default;
    /**
     * \brief Move constructor
     */
    Cipher(Cipher&& rhs) = default;
    /**
     * \brief Copy assignment operator
     */
    Cipher& operator=(const Cipher& rhs) = default;
    /**
     * \brief Move assignment operator
     */
    Cipher& operator=(Cipher&& rhs) = default;

    /**
     * \brief Destructor
     */
    virtual ~Cipher() = default;

   
    virtual std::string applyCipher(const std::string& input,
                                    const CipherMode mode) const = 0;
};


#endif