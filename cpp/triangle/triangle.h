#if !defined(TRIANGLE_H)
#define TRIANGLE_H
// should I have an "#include <stdexcept>" here because kind implicitly throws an exception? Or is it
// ok to keep the include in the cpp file?
namespace triangle 
{
    enum class flavor 
    {
        equilateral,
        isosceles,
        scalene
    };

    flavor kind(double side_length1, double side_length2, double side_length3);

}  // namespace triangle


#endif // TRIANGLE_H