#include "space_age.h"

namespace space_age {
    space_age::space_age(long long age_in_seconds) : 
        age_in_seconds{age_in_seconds}, 
        earth_years{static_cast<double>(age_in_seconds)/seconds_in_earth_year}
    {};

    long long space_age::seconds() const {
        return age_in_seconds;
    }
    double space_age::on_mercury() const {
        return earth_years / mercury_year_in_earth_years;
    }
    double space_age::on_venus() const {
        return earth_years / venus_year_in_earth_years;
    }
    double space_age::on_earth() const {
        return earth_years;
    }
    double space_age::on_mars() const {
        return earth_years / mars_year_in_earth_years;
    }
    double space_age::on_jupiter() const {
        return earth_years / jupiter_year_in_earth_years;
    }
    double space_age::on_saturn() const {
        return earth_years / saturn_year_in_earth_years;
    }
    double space_age::on_uranus() const {
        return earth_years / uranus_year_in_earth_years;
    }
    double space_age::on_neptune() const {
        return earth_years / neptune_year_in_earth_years;
    }

}  // namespace space_age
