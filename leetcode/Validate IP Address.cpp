class Solution {
public:
    string validIPAddress(string IP) {
        regex ipv4_regex("^((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])$");
        if(regex_match(IP,ipv4_regex)){
            return "IPv4";   
        }
        regex ipv6_regex("(([0-9a-fA-F]{1,4}:)([0-9a-fA-F]{1,4}:)([0-9a-fA-F]{1,4}:)([0-9a-fA-F]{1,4}:)([0-9a-fA-F]{1,4}:)([0-9a-fA-F]{1,4}:)([0-9a-fA-F]{1,4}:)([0-9a-fA-F]{1,4}))");
        if(regex_match(IP,ipv6_regex)){
            return "IPv6";   
        }
        return "Neither";
    }
};