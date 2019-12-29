#include <iostream>
#include "Encrypters.h"

int main()
{
    std::string test = "This is a test string";

    Encrypters::Encrypter encrypter;

    Encrypters::MegaEncrypt megaEncrypt;
    Encrypters::SuperEncrypt superEncrypt;

    encrypter.SelectAlgorithm(megaEncrypt);

    encrypter.EncryptString("this is a string");

    encrypter.PresentCode();

    encrypter.SelectAlgorithm(superEncrypt);

    encrypter.EncryptString("This is a string");

    encrypter.PresentCode();

    return 0;
}