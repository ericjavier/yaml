#ifndef ZIP_HPP_INCLUDED
#define ZIP_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/zip_with.hpp>

BEGIN_YAML_NSP

using zip = apply<zip_with, make_pair>::type;

END_YAML_NSP

#endif ZIP_HPP_INCLUDED