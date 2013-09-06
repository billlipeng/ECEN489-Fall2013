
/// \file temp-conv.cc
///
/// Implements a small utility that reads a list of temperatures from stdin,
/// terminated by EOF, and then outputs the converted temperatures.
///
/// Usage: temp-conv [options] <source scale> <target scale>
///
/// The source and target scales may be any substrings of (F|f)ahrenheit,
/// (C|c)elsius, or (K|k)elvin.
///
/// Options:
///     -h, --help:       Print an explanatory help text.
///     -s, --statistics: Print statistics of the processed temperatures.

#include <array>
#include <iostream>
#include <limits>
#include <string>
#include <tuple>
#include <vector>

#include "mismatch.hh"

enum class scale_type {celsius, kelvin, fahrenheit};

int main(int argc, char **argv)
{
    // Check arguments.  Typically, I would use boost::program_options for this,
    // but that would require the grader to have it on their machine.

    // We expect two positional arguments, the source and target scales.
    const int expect_positionals = 2;
    int cur_positional = 0;
    scale_type source_scale;
    scale_type target_scale;

    // We accept "help" and "statistics". Specifying an unknown option or
    // otherwise messing up the arguments also prints the help text.
    bool arg_help = false;
    bool arg_statistics = false;

    // Start processing args at index 1, because 
    for(int cur_arg = 1; cur_arg < argc; ++cur_arg)
    {
        std::string cur_arg_string(argv[cur_arg]);
        
        // Detect an option.
        if(cur_arg_string[0] == '-')
        {
            std::string::iterator text_begin = begin(cur_arg_string);

            // Munch any leading hyphens.
            while(text_begin != end(cur_arg_string) && (*text_begin) == '-')
                ++text_begin;

            // Check that we still have argument text left after munching.
            if(text_begin == end(cur_arg_string))
            {
                std::cerr << "Error: Empty argument supplied." << std::endl;
                arg_help = true;
                goto process_args_end;
            }

            // Check the argument text against the arguments we accept
            // (currently, only "help" and "statistics").
            std::string help_string("help");
            auto help_differing_pair = cpp14_compat::mismatch(
                    text_begin,
                    end(cur_arg_string), 
                    begin(help_string),
                    end(help_string)
            );

            std::string statistics_string("statistics");
            auto statistics_differing_pair = cpp14_compat::mismatch(
                text_begin,
                end(cur_arg_string),
                begin(statistics_string),
                end(statistics_string)
            );
            
            // If the mismatch occured at the first character of the
            // user-supplied text, then it's not a match.  Otherwise, it is (we
            // don't worry about possibly conflicting matches).
            if(std::get<0>(help_differing_pair) != text_begin)
            {
                arg_help = true;
            }
            else if(std::get<0>(statistics_differing_pair) != text_begin)
            {
                arg_statistics = true;
            }
            else
            {
                std::cerr << "Error: unknown argument \"" << cur_arg_string
                          << "\" supplied." << std::endl;
                arg_help = true;
                goto process_args_end;
            }
        }
        else
        {
            // This token is a positional option.

            // Make sure we haven't already received enough positional options.
            if(cur_positional >= expect_positionals)
            {
                std::cerr << "Error: Too many positional options specified."
                          << std::endl;
                arg_help = true;
                goto process_args_end;
            }

            // The positional argument specifies a scale.
            bool existing_scale_was_specified = false;
            scale_type cur_scale;
            
            typedef std::tuple<std::string, scale_type> scale_mapping;

            std::array<scale_mapping, 6> accepted_scales = {
                std::make_tuple("celsius", scale_type::celsius),
                std::make_tuple("Celsius", scale_type::celsius),
                std::make_tuple("kelvin", scale_type::kelvin),
                std::make_tuple("Kelvin", scale_type::kelvin),
                std::make_tuple("fahrenheit", scale_type::fahrenheit),
                std::make_tuple("Fahrenheit", scale_type::fahrenheit)
            };
            
            // Check the positional argument against each of the accepted
            // scales.
            for(const scale_mapping &check_mapping : accepted_scales)
            {
                const std::string &check_name = std::get<0>(check_mapping);
                const scale_type &check_scale = std::get<1>(check_mapping);

                auto differing_pair = cpp14_compat::mismatch(
                    begin(cur_arg_string),
                    end(cur_arg_string),
                    begin(check_name),
                    end(check_name)
                );

                // If the user-supplied text and the text to check against
                // differ after the first character, then we assume that was the
                // correct option.
                if(std::get<0>(differing_pair) != begin(cur_arg_string))
                {
                    cur_scale = check_scale;
                    existing_scale_was_specified = true;
                    break;
                }
            }

            if(! existing_scale_was_specified)
            {
                std::cerr << "Error: Unknown temperature scale \""
                          << cur_arg_string << "\"." << std::endl;
                arg_help = true;
                goto process_args_end;
            }

            if(cur_positional == 0)
            {
                source_scale = cur_scale;
            }
            else if(cur_positional == 1)
            {
                target_scale = cur_scale;
            }

            ++cur_positional;
        }
            
    }
 process_args_end:

    // Check to make sure that we got two positional options.
    if(cur_positional != 2)
    {
        std::cerr << "Error: You must specify both a source and target scale."
                  << std::endl;
        arg_help = true;
    }

    // Check to see if we need to print help text, wither from --help argument
    // or from error.
    if(arg_help)
    {
        std::cerr << "Usage: temp-conv [options] <source scale> <target scale>"
                  << std::endl;
        std::cerr << "The source and target scales may be any substring of"
            " (C|c)elsius, (K|k)elvin, or (F|f)ahrenheit." << std::endl;

        std::cerr << "Options: " << std::endl
                  << "\t-h, --help: Print this help text."
                  << std::endl
                  << "\t-s, --statistics: Print statistics of processed records."
                  << std::endl;
        
        return 1;
    }

    // Now we have a source scale and a target scale.  We need to read input
    // temperatures until EOF, outputing their converted equivalents.
    size_t processed_records = 0;
    while(std::cin)
    {
        double input_temp = std::numeric_limits<double>::signaling_NaN();
        std::cin >> input_temp;

        // Check to see if input stream has closed or we have had a read error.
        if(! std::cin)
        {
            break;
        }        

        double celsius_equiv = std::numeric_limits<double>::signaling_NaN();

        if(source_scale == scale_type::celsius)
        {
            celsius_equiv = input_temp;
        }
        else if(source_scale == scale_type::kelvin)
        {
            celsius_equiv = input_temp - 273.15;
        }
        else if(source_scale == scale_type::fahrenheit)
        {
            celsius_equiv = (input_temp - 32) * 5.0 / 9.0;
        }

        double target_temp = std::numeric_limits<double>::signaling_NaN();

        if(target_scale == scale_type::celsius)
        {
            target_temp = celsius_equiv;
        }
        else if(target_scale == scale_type::kelvin)
        {
            target_temp = celsius_equiv + 273.15;
        }
        else if(target_scale == scale_type::fahrenheit)
        {
            target_temp = (celsius_equiv * 9.0 / 5.0) + 32;
        }

        std::cout << target_temp << std::endl;

        ++processed_records;
    }
    
    if(! std::cin.eof())
    {
        std::cerr << "Error: Malformed input record "
                  << (processed_records - 1) << std::endl;
    }

    if(arg_statistics)
    {
        std::cerr << "Processed " << processed_records << " records."
                  << std::endl;
    }
}

