int64_t convert_string_to_number(string input, int64_t& position) {
    string number = "";
    
    while(position < input.size() && isdigit(input.at(position))) {
        number += input.at(position);
        position++;
    }

    return stoll(number);
}
