#pragma once
#include <string>

namespace Encrypters {

	class EncrypterAlgo {

	public:
		virtual void Encrypt(std::string source) = 0;
		virtual void Decrypt(std::string source) = 0;

	};

	class Encrypter {

	private:
		EncrypterAlgo* Algorithm;

	public:
		void SelectAlgorithm(EncrypterAlgo&& algorithm) { Algorithm = &algorithm; }
		void EncryptString(std::string&& str) { Algorithm->Encrypt(str); }
		void DecryptString(std::string&& str) { Algorithm->Decrypt(str); }
	};

}