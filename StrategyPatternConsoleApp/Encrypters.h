#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace Encrypters {

	class EncrypterAlgo {

	public:
		virtual void Encrypt(const std::string source, std::vector<unsigned long>& code) = 0;
		virtual void Decrypt(std::string& source, const std::vector<unsigned long> code) = 0;

	};

	class SuperEncrypt : public EncrypterAlgo
	{
		virtual void Encrypt(const std::string source, std::vector<unsigned long>& code)
		{
			unsigned long long charCode = 0;

			for (auto i = source.cbegin(); i != source.cend(); i++)
			{
				charCode = (unsigned long long)*i;
				charCode = charCode + 41 * 23 - 3 * 1111;
				code.push_back(charCode);
			}
		}

		virtual void Decrypt(std::string& source, const std::vector<unsigned long> code)
		{
			unsigned long long stringCode;

			for (auto i = code.cbegin(); i != code.cend(); i++)
			{
				stringCode = *i;
				stringCode = stringCode - 41 / 23 + 3 / 1111;
				source.push_back(stringCode);
			}
		}
	};

	class HyperEncrypt : protected EncrypterAlgo
	{
		virtual void Encrypt(const std::string source, std::vector<unsigned long>& code)
		{
			unsigned long long charCode = 0;

			for (auto i = source.cbegin(); i != source.cend(); i++)
			{
				charCode = (unsigned long long) * i;
				charCode = charCode * 31416;
				code.push_back(charCode);
			}
		}

		virtual void Decrypt(std::string& source, const std::vector<unsigned long> code)
		{
			unsigned long long stringCode;

			for (auto i = code.cbegin(); i != code.cend(); i++)
			{
				stringCode = *i;
				stringCode = stringCode / 31416;
				source.push_back(stringCode);
			}
		}
	};

	class MegaEncrypt : public EncrypterAlgo
	{
		virtual void Encrypt(const std::string source, std::vector<unsigned long>& code)
		{
			unsigned long long charCode = 0;

			for (auto i = source.cbegin(); i != source.cend(); i++)
			{
				charCode = (unsigned long long) * i;
				charCode = charCode + 7;
				code.push_back(charCode);
			}
		}

		virtual void Decrypt(std::string& source, const std::vector<unsigned long> code)
		{
			unsigned long long stringCode;

			for (auto i = code.cbegin(); i != code.cend(); i++)
			{
				stringCode = *i;
				stringCode = stringCode - 7;
				source.push_back(stringCode);
			}
		}
	};

	class Encrypter {
	private:
		EncrypterAlgo* Algorithm;
		std::vector<std::string> EncryptedStrings;
		std::vector<std::string> DecryptedStrings;
		std::vector<unsigned long> Code;
	public:
		void SelectAlgorithm(EncrypterAlgo& algorithm) { Algorithm = &algorithm; }
		void EncryptString(std::string&& str) { EncryptedStrings.push_back(str); Algorithm->Encrypt(str, Code); }
		void DecryptString(std::vector<unsigned long> code) {Algorithm->Decrypt(EncryptedStrings[0], code); }
		void PresentEncryptedString() { std::cout << EncryptedStrings[0] << "\n"; }
		void PresentCode() { for (auto i : Code) { std::cout << i << " "; } std::cout << "\n"; }
	};

}