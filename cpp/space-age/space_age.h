#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age {
    class space_age {
        const long long age_in_seconds;
        const double earth_years;
        public:
        explicit space_age(long long age_in_seconds); // initializer
        long long seconds() const;
        double on_mercury() const;
        double on_venus() const;
        double on_earth() const;
        double on_mars() const;
        double on_jupiter() const;
        double on_saturn() const;
        double on_uranus() const;
        double on_neptune() const;
    };
    static constexpr double seconds_in_earth_year = 31557600.0;
    static constexpr double mercury_year_in_earth_years = 0.2408467;
    static constexpr double venus_year_in_earth_years = 0.61519726;
    static constexpr double mars_year_in_earth_years = 1.8808158;
    static constexpr double jupiter_year_in_earth_years = 11.862615;
    static constexpr double saturn_year_in_earth_years = 29.447498;
    static constexpr double uranus_year_in_earth_years = 84.016846;
    static constexpr double neptune_year_in_earth_years = 164.79132;
}  // namespace space_age

#endif // SPACE_AGE_H