#pragma once

#include "base_exception.hpp"

#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <utility>

namespace orlov {
    class illegal_menu_exception final : public base_exception {
    public:
        explicit illegal_menu_exception(const std::string &what_arg) :
                base_exception(what_arg) {}
    };

    class menu {
    private:
        using option_storage = std::map<const std::string, std::function<void()>>;

    public:
        using option = std::pair<option_storage::key_type, option_storage::mapped_type>;

        explicit menu(std::initializer_list<option> options, std::istream &in = std::cin, std::ostream &out = std::cout)
                :
                options_{std::move(options)},
                in_{in},
                out_{out} {
            if (options_.empty()) {
                throw illegal_menu_exception("menu cannot be empty");
            }
        }

        void show() {
            out_ << "(0) back\n";
            size_t idx = 1;
            std::transform(options_.cbegin(), options_.cend(), std::ostream_iterator<std::string>(out_, "\n"),
                           [&idx](const option &o) {
                               using namespace std::string_literals;
                               return "("s + std::to_string(idx++) + ") "s + o.first;
                           });
            out_ << "> ";
            int selection_index;
            in_ >> selection_index;

            if (selection_index == 0) {
                return;
            }
            if ((selection_index < 0) || (selection_index > static_cast<int>(count()))) {
                out_ << "try again\n";
                show();
            } else {
                auto selected_option = options_.cbegin();
                std::advance(selected_option, selection_index - 1);
                const auto &action = selected_option->second;
                action();
            }


        }

    private:
        size_t count() const {
            return options_.size();
        }

        option_storage options_;
        std::istream &in_ = std::cin; // FIXME get rid
        std::ostream &out_ = std::cout; // FIXME get rid
    };
}
