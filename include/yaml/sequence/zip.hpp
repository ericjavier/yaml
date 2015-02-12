#ifndef ZIP_HPP_INCLUDED
#define ZIP_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/zip_with.hpp>

BEGIN_YAML_NSP

using zip = zip_with::ret<make_pair>;

END_YAML_NSP

#endif ZIP_HPP_INCLUDED