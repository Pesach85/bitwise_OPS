#pragma once

#include "inputbox_h.h"
#include <templates.h>

static const std::vector <std::string> allowed_inp = { "A", "B", "C", "D", "E", "F", "a", "b", "c", "d", "e", "f", "x" };
static const std::vector <std::string> allowed_inp_2 = { "&", "|", "^", ">>", "<<","~", "toggle"};

int elab_inputs(std::vector <std::string> tokens)
{
    std::stringstream to_print;

    uint8_t check_bit_res_8 = 0;
    uint16_t check_bit_res_16 = 0;
    uint32_t check_bit_res_32 = 0;
    uint64_t check_bit_res_64 = 0;

    hex_num_cstr = tokens[0].c_str();

    // Now you can use the vector (tokens) as you would like. Below the contents are printed.
    /*
    for (auto& x : tokens)            // for each token in 'tokens' vector,
        std::cout << x << ' ';          // print out token with a space at the end

    std::cout << "\n\n";
    */
    /*
    for (int i = 0; i < tokens.size(); i++)           // for each token in 'tokens' vector,
        std::cout << i << ": " << tokens[i] << '\n';    // print out index number and token
    */
    /*
    *
    for (auto a_elt : a) {
        if (std::find(b.begin(), b.end(), a_elt) == b.end()) {
            return false;
        }
    }


    */

    if (tokens.size() < 2)
    {
        bool is_hex = false;
        for (auto a : allowed_inp) {
            for (int i = 0; i < strlen(hex_num_cstr); i++)
            {
                std::string temp = {};
                temp = std::toupper(hex_num_cstr[i]);
                if (temp[0] != a[0])
                {
                    if (isalpha(hex_num_cstr[1])) is_hex = true;
                    break;
                }
                else
                {
                    is_hex = true;
                    break;
                }
            }
        }
        if (is_hex)
        {
            std::cout << "\n" << hex_num_cstr << "\n";
            if (foo(hex_num_cstr) <= UCHAR_MAX)
            {
                check_bit_res_8 = (uint8_t)foo(hex_num_cstr);
                //std::cout << foo(hex_num_cstr) << "\n";
                std::cout << "Decimale: " << +check_bit_res_8 << "\n";

                bool bits_read[CHAR_BIT] = { 0 };

                uint8_t number;
                uint8_t number_pr;
                number_pr = check_bit_res_8; //0b00000101
                number = reverse_bits(number_pr);

                /*
                for (int i = 0; i < CHAR_BIT; i++)
                {
                    bits_read[i] = BitVal(+number, i);
                    if (i == 0)
                    {
                        to_print << "\n" << "[Bit " << i << "]: " << +bits_read[i];
                    }
                    else
                    {
                        to_print << ", [Bit " << i << "]: " << +bits_read[i];
                    }
                }*/
                for (int i = 0; i < CHAR_BIT; i++)
                {
                    bits_read[i] = BitVal(+number, i);
                    if (i == 0)
                    {
                        to_print << "\n" << +bits_read[i];
                    }
                    else
                    {
                        if ((i & 3) == 0)
                        {
                            to_print << " " << +bits_read[i];
                        }
                        else
                        {
                            to_print << +bits_read[i];
                        }

                    }
                }

            }
            else if ((foo(hex_num_cstr) > UCHAR_MAX) && (foo(hex_num_cstr) <= USHRT_MAX))
            {
                check_bit_res_16 = (uint16_t)foo(hex_num_cstr);
                //std::cout << foo(hex_num_cstr) << "\n";
                std::cout << "Decimale: " << +check_bit_res_16 << "\n";

                bool bits_read[2 * CHAR_BIT] = { 0 };

                uint16_t number;
                uint16_t number_pr;
                number_pr = check_bit_res_16; //0b0000 0000 0000 0000
                number = reverse_bits(number_pr);

                /*
                for (int i = 0; i < 2 * CHAR_BIT; i++)
                {
                    bits_read[i] = BitVal(+number, i);
                    if (i == 0)
                    {
                        to_print << "\n" << "[Bit " << i << "]: " << +bits_read[i];
                    }
                    else
                    {
                        to_print << ", [Bit " << i << "]: " << +bits_read[i];
                    }
                }*/
                for (int i = 0; i < 2 * CHAR_BIT; i++)
                {
                    bits_read[i] = BitVal(+number, i);
                    if (i == 0)
                    {
                        to_print << "\n" << +bits_read[i];
                    }
                    else
                    {
                        if ((i & 3) == 0)
                        {
                            to_print << " " << +bits_read[i];
                        }
                        else
                        {
                            to_print << +bits_read[i];
                        }

                    }
                }

            }
            else if ((foo(hex_num_cstr) > USHRT_MAX) && (foo(hex_num_cstr) <= UINT_MAX))
            {
                check_bit_res_32 = (uint32_t)foo(hex_num_cstr);
                //std::cout << foo(hex_num_cstr) << "\n";
                std::cout << "Decimale: " << +check_bit_res_32 << "\n";

                bool bits_read[4 * CHAR_BIT] = { 0 };

                uint32_t number;
                uint32_t number_pr;
                number_pr = check_bit_res_32; //0b 0000 0000 0000 0000 0000 0000 0000 0000
                number = reverse_bits(number_pr);
                /*
                for (int i = 0; i < 4 * CHAR_BIT; i++)
                {
                    bits_read[i] = BitVal(+number, i);
                    if (i == 0)
                    {
                        to_print << "\n" << "[Bit " << i << "]: " << +bits_read[i];
                    }
                    else
                    {
                        to_print << ", [Bit " << i << "]: " << +bits_read[i];
                    }
                }*/
                for (int i = 0; i < 4 * CHAR_BIT; i++)
                {
                    bits_read[i] = BitVal(+number, i);
                    if (i == 0)
                    {
                        to_print << "\n" << +bits_read[i];
                    }
                    else
                    {
                        if ((i & 3) == 0)
                        {
                            to_print << " " << +bits_read[i];
                        }
                        else
                        {
                            to_print << +bits_read[i];
                        }

                    }
                }

            }
            else if ((foo(hex_num_cstr) > UINT_MAX))
            {
                check_bit_res_64 = foo(hex_num_cstr);
                //std::cout << foo(hex_num_cstr) << "\n";
                std::cout << "Decimale: " << +check_bit_res_64 << "\n";

                bool bits_read[8 * CHAR_BIT] = { 0 };

                uint64_t number;
                uint64_t number_pr;
                number_pr = check_bit_res_64; //0b 0000 0000 0000 0000 0000 0000 0000 0000 
                number = reverse_bits(number_pr);

                /*
                for (int i = 0; i < 8 * CHAR_BIT; i++)
                {
                    bits_read[i] = BitVal(+number, i);
                    if (i == 0)
                    {
                        to_print << "\n" << "[Bit " << i << "]: " << +bits_read[i];
                    }
                    else
                    {
                        to_print << ", [Bit " << i << "]: " << +bits_read[i];
                    }
                }
                */
                for (int i = 0; i < 8 * CHAR_BIT; i++)
                {
                    bits_read[i] = BitVal(+number, i);
                    if (i == 0)
                    {
                        to_print << "\n" << +bits_read[i];
                    }
                    else
                    {
                        if ((i & 3) == 0)
                        {
                            to_print << " " << +bits_read[i];
                        }
                        else 
                        {
                            to_print << +bits_read[i];
                        }
                        
                    }
                }


            }

            /*
            uint8_t bit_0 = BitVal(+number, 0); // bit_4 = 0
            uint8_t bit_1 = BitVal(+number, 1); // bit_1 = 0
            uint8_t bit_2 = BitVal(+number, 2); // bit_2 = 0
            uint8_t bit_3 = BitVal(+number, 3); // bit_3 = 0
            uint8_t bit_4 = BitVal(+number, 4); // bit_4 = 0
            uint8_t bit_5 = BitVal(+number, 5); // bit_5 = 1
            uint8_t bit_6 = BitVal(+number, 6); // bit_6 = 0
            uint8_t bit_7 = BitVal(+number, 7); // bit_7 = 1
            */

            // std::cout << "\nDEC number: " << +number_pr << ", [Bit 0]: " << +bits_read[0] << ", [Bit 1]: " << +bits_read[1] << ", [Bit2]: " << +bits_read[2] << ", [Bit3]: " << +bits_read[3] << ", [Bit4]: " << +bits_read[4] << ", [Bit5]: " << +bits_read[5] << ", [Bit6]: " << +bits_read[6] << ", [Bit7]: " << +bits_read[7] <<"\n";
            // std::cout << +number << "\n";
            std::cout << to_print.rdbuf();
            std::cout << "\n\n";
            MessageBox(nullptr, TEXT("Operazione completata"), TEXT("Fine"), MB_OK);
            std::cout << std::endl;


        }

    }
    else if (tokens.size() == 2) {
        bool is_tog = false;
        if ((tokens.at(1) == "toggle") || (tokens.at(1) == "~")) is_tog = true;

        if (is_tog) {

            std::cout << "\n" << hex_num_cstr << " logic operation " << tokens[1].c_str() << "\n";
            if (foo(hex_num_cstr) <= UCHAR_MAX)
            {
                uint8_t result = 0;
                uint8_t num1 = 0;
                num1 = (uint8_t)foo(hex_num_cstr);
                result = Togle(num1);
                std::cout << "Datatype is: unsigned char" << "\n";
                std::cout << "Decimal result is: " << +result << "\n";
                std::cout << "Hex result is: " << ToHex<unsigned char>(+result) << "\n\n";
            }
            else if ((foo(hex_num_cstr) > UCHAR_MAX) && (foo(hex_num_cstr) <= USHRT_MAX))
            {
                uint16_t result = 0;
                uint16_t num1 = 0;
                num1 = (uint16_t)foo(hex_num_cstr);
                result = Togle(num1);
                std::cout << "Datatype is: unsigned short" << "\n";
                std::cout << "Decimal result is: " << +result << "\n";
                std::cout << "Hex result is: " << ToHex<unsigned short>(+result) << "\n\n";
            }
            else if ((foo(hex_num_cstr) > USHRT_MAX) && (foo(hex_num_cstr) <= UINT_MAX))
            {
                uint32_t result = 0;
                uint32_t num1 = 0;
                num1 = (uint32_t)foo(hex_num_cstr);
                result = Togle(num1);
                std::cout << "Datatype is: uint32_t" << "\n";
                std::cout << "Decimal result is: " << +result << "\n";
                std::cout << "Hex result is: " << ToHex<unsigned long>(+result) << "\n\n";
            }
            else if (foo(hex_num_cstr) > UINT_MAX)
            {
                uint64_t result = 0;
                uint64_t num1 = 0;
                num1 = foo(hex_num_cstr);
                result = Togle(num1);
                std::cout << "Datatype is: unsigned long" << "\n";
                std::cout << "Decimal result is: " << +result << "\n";
                std::cout << "Hex result is: " << ToHex<uint64_t>(+result) << "\n\n";
            }

        }

    }
    else if (tokens.size() >= 3)
    {
        bool islogicop = false;
        bool is_and = false;
        bool is_or = false;
        bool is_xor = false;
        bool is_shift_l = false;
        bool is_shift_r = false;

        if (tokens.at(1) == "&" || tokens.at(1) == "^" || tokens.at(1) == "|" || tokens.at(1) == "<<" || tokens.at(1) == ">>")
        {
            islogicop = !islogicop;
            if (tokens.at(1) == "&") is_and = true;
            else if (tokens.at(1) == "|") is_or = true;
            else if (tokens.at(1) == "^") is_xor = true;
            else if (tokens.at(1) == "<<") is_shift_l = true;
            else if (tokens.at(1) == ">>") is_shift_r = true;      
        }

        if (islogicop) {
            hex_num_cstr_2 = tokens[2].c_str();
            std::cout << "\n" << hex_num_cstr << " logic operation " << tokens[1].c_str() << " with " << hex_num_cstr_2 << "\n";
            if (foo(hex_num_cstr) <= UCHAR_MAX)
            {
                uint8_t result = 0;
                uint8_t num1 = 0;
                uint8_t num2 = 0;
                num1 = (uint8_t)foo(hex_num_cstr);
                num2 = (uint8_t)foo(hex_num_cstr_2);

                if (is_shift_l || is_shift_r) num2 = (uint8_t)atoi(hex_num_cstr_2);
                
                if (is_and) result = num1 & num2;
                else if (is_or) result = num1 | num2;
                else if (is_xor) result = num1 ^ num2;
                else if (is_shift_l) result = num1 << num2;
                else if (is_shift_r) result = num1>>num2;

                std::cout << "Datatype is: unsigned char" << "\n";
                std::cout << "Decimal result is: " << +result << "\n";
                std::cout << "Hex result is: " << ToHex<unsigned char>(+result) << "\n\n";
            }
            else if ((foo(hex_num_cstr) > UCHAR_MAX) && (foo(hex_num_cstr) <= USHRT_MAX))
            {
                uint16_t result = 0;
                uint16_t num1 = 0;
                uint16_t num2 = 0;
                num1 = (uint16_t)foo(hex_num_cstr);
                num2 = (uint16_t)foo(hex_num_cstr_2);

                if (is_shift_l || is_shift_r) num2 = (uint16_t)atoi(hex_num_cstr_2);

                if (is_and) result = num1 & num2;
                else if (is_or) result = num1 | num2;
                else if (is_xor) result = num1 ^ num2;
                else if (is_shift_l) result = num1<<num2;
                else if (is_shift_r) result = num1>>num2;

                std::cout << "Datatype is: unsigned short" << "\n";
                std::cout << "Decimal result is: " << +result << "\n";
                std::cout << "Hex result is: " << ToHex<unsigned short>(+result) << "\n\n";
            }
            else if ((foo(hex_num_cstr) > USHRT_MAX) && (foo(hex_num_cstr) <= UINT_MAX))
            {
                uint32_t result = 0;
                uint32_t num1 = 0;
                uint32_t num2 = 0;
                num1 = (uint32_t)foo(hex_num_cstr);
                num2 = (uint32_t)foo(hex_num_cstr_2);

                if (is_shift_l || is_shift_r) num2 = (uint32_t)atoi(hex_num_cstr_2);

                if (is_and) result = num1 & num2;
                else if (is_or) result = num1 | num2;
                else if (is_xor) result = num1 ^ num2;
                else if (is_shift_l) result = num1<<num2;
                else if (is_shift_r) result = num1>>num2;

                std::cout << "Datatype is: uint32_t" << "\n";
                std::cout << "Decimal result is: " << +result << "\n";
                std::cout << "Hex result is: " << ToHex<unsigned long>(+result) << "\n\n";
            }
            else if (foo(hex_num_cstr) > UINT_MAX)
            {
                uint64_t result = 0;
                uint64_t num1 = 0;
                uint64_t num2 = 0;
                num1 = foo(hex_num_cstr);
                num2 = foo(hex_num_cstr_2);

                if (is_shift_l || is_shift_r) num2 = (uint64_t)atoi(hex_num_cstr_2);

                if (is_and) result = num1 & num2;
                else if (is_or) result = num1 | num2;
                else if (is_xor) result = num1 ^ num2;
                else if (is_shift_l) result = num1<<num2;
                else if (is_shift_r) result = num1>>num2;

                std::cout << "Datatype is: uint64_t" << "\n";
                std::cout << "Decimal result is: " << +result << "\n";
                std::cout << "Hex result is: " << ToHex<unsigned long long>(+result) << "\n\n";
            }
        }
    }
    tokens.clear();
    return 0;
}