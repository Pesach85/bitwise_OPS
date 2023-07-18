#define BitVal(data,y) ( (data>>y) & 1)      /** Return Data.Y value   **/
#define SetBit(data,y)    data |= (1 << y)    /** Set Data.Y   to 1    **/
#define ClearBit(data,y)  data &= ~(1 << y)   /** Clear Data.Y to 0    **/
#define TogleBit(data,y)     (data ^=BitVal(y))     /** Togle Data.Y  value  **/
#define Togle(data)   (data =~data )         /** Togle Data value     **/

#include <proc_inputs.h>
#include <input_box.h>
#include <windows_format.h>


int main()
{
    bool with_window = false;
    std::string line;

    while (true) {
        std::cout << "Enter bit operation to elaborate: ";
        std::getline(std::cin, line);

        if (line == "stop" || line =="exit") exit(0);        // Enter stop to quit program

        std::stringstream ss(line);       // constructor sets 'line' as contents of the stream
        std::vector <std::string> tokens;   // where our tokenised input is stored
        std::string temp;                   // where current token is temporarily loaded before it's put into the vector

        while (getline(ss, temp, ' '))   // extract characters from ss until a space is found and stores them in temp
            tokens.push_back(temp);       // put the token formed by getline in our vector, from back so order is kept

        /*

          Now you can use the vector as you would like. Below the contents are printed.

         */
        hex_num_cstr = { 0 };
        
  
        //std::cout << hex_num_cstr << "\n";
        // check if inserted value is null before to calculate
        if (!tokens.empty())
        {
            if (tokens.at(0) == "w")
            {            
                first_input_window();
                if (result_inp != "")
                {
                    tokens.push_back(result_inp);
                }
                with_window = true;
            }
            else if (isalpha(tokens[0].c_str()[0]))
            {
                std::string full_hex = "0x0";
                full_hex += tokens[0].c_str();
                std::cout << "\n" << full_hex;
                tokens[0].clear();
                tokens[0] = full_hex;
            }
            else if ((isdigit(tokens[0].c_str()[0])) && (!isalpha(tokens[0].c_str()[1])))
            {
                std::string full_hex = "0x0";
                full_hex += tokens[0].c_str();
                std::cout << "\n" << full_hex;
                tokens[0].clear();
                tokens[0] = full_hex;
            }
            elab_inputs(tokens);
        }
        else
        {
            std::cout << "\n";
            main();
        }
    }
    return 0;
}