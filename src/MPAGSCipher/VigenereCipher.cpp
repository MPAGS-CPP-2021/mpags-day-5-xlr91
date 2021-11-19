#include "VigenereCipher.hpp"
#include "Alphabet.hpp"

#include <string>
#include <algorithm>
#include <iostream>

VigenereCipher::VigenereCipher(const std::string& key)
{
    setKey(key);
}

void VigenereCipher::setKey(const std::string& key)
{
    //store the key
    key_ = key;

    //Make sure key is uppercase
    std::transform(key_.begin(), key_.end(), key_.begin(), ::toupper);

    //remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));
    //cheeck if the key is empty and replace it with default if so

    if(key_.empty()){
        key_ = "KEY"; //default
    }

    std::size_t letpos{0};
    for (char const &c : key_){
        letpos = Alphabet::alphabet.find(c);

        CaesarCipher cc{letpos};
        std::pair<char, CaesarCipher> p{c, cc};
        charLookup_.insert(p);
    }

    //loop over the key
    
        //find the letter position in the alphabet
        //create caesarecipher using this position as a key
        //insert a std::pair of the letter and caesar cipher into the lookcup
}


std::string VigenereCipher::returnKey() const{
    return key_;
}

std::string VigenereCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{

    std::string outputText;
    
    for(std::size_t i{0}; i < inputText.size(); ++i){
        char keychar = key_.at(i % key_.size()); //find and repeat

        CaesarCipher currentCaesar{charLookup_.at(keychar)};

        std::string cipherstring = "";
        cipherstring +=  inputText.at(i);
    
        outputText += currentCaesar.applyCipher(cipherstring ,cipherMode);
    }
    
    //for each letter in input:
        // find corresponding letterin key
        //repeat/truncate as required
        //find caesarcipher from lookup
        //run en/dycrytoin
        //add result to output

    

    return outputText;
}

