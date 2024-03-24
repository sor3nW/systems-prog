BEGIN {
    FS=","
}

# Process each line of input
{
    # Initialize variables
    in_quotes = 0
    line = ""

    # Loop through each character in the line
    for (i = 1; i <= length($0); i++) {
        char = substr($0, i, 1)

        # Toggle in_quotes flag when encountering double quotes
        if (char == "\"") {
            in_quotes = 1 - in_quotes
            next
        }

        # If char is a comma and not within quotes, print line and reset
        if (char == "," && !in_quotes) {
            print line
            line = ""
            next
        }

        # Append char to line
        line = line char
    }

    # Print the remaining line
    print line
}BEGIN {
    FS=","
}

# Process each line of input
{
    # Initialize variables
    in_quotes = 0
    line = ""

    # Loop through each character in the line
    for (i = 1; i <= length($0); i++) {
        char = substr($0, i, 1)

        # Toggle in_quotes flag when encountering double quotes
        if (char == "\"") {
            in_quotes = 1 - in_quotes
            next
        }

        # If char is a comma and not within quotes, print line and reset
        if (char == "," && !in_quotes) {
            print line
            line = ""
            next
        }

        # Append char to line
        line = line char
    }

    # Print the remaining line
    print line
}
END{

}
