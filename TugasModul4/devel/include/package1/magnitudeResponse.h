// Generated by gencpp from file package1/magnitudeResponse.msg
// DO NOT EDIT!


#ifndef PACKAGE1_MESSAGE_MAGNITUDERESPONSE_H
#define PACKAGE1_MESSAGE_MAGNITUDERESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace package1
{
template <class ContainerAllocator>
struct magnitudeResponse_
{
  typedef magnitudeResponse_<ContainerAllocator> Type;

  magnitudeResponse_()
    : magnitude(0.0)  {
    }
  magnitudeResponse_(const ContainerAllocator& _alloc)
    : magnitude(0.0)  {
  (void)_alloc;
    }



   typedef double _magnitude_type;
  _magnitude_type magnitude;





  typedef boost::shared_ptr< ::package1::magnitudeResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::package1::magnitudeResponse_<ContainerAllocator> const> ConstPtr;

}; // struct magnitudeResponse_

typedef ::package1::magnitudeResponse_<std::allocator<void> > magnitudeResponse;

typedef boost::shared_ptr< ::package1::magnitudeResponse > magnitudeResponsePtr;
typedef boost::shared_ptr< ::package1::magnitudeResponse const> magnitudeResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::package1::magnitudeResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::package1::magnitudeResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::package1::magnitudeResponse_<ContainerAllocator1> & lhs, const ::package1::magnitudeResponse_<ContainerAllocator2> & rhs)
{
  return lhs.magnitude == rhs.magnitude;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::package1::magnitudeResponse_<ContainerAllocator1> & lhs, const ::package1::magnitudeResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace package1

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::package1::magnitudeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::package1::magnitudeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::package1::magnitudeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::package1::magnitudeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::package1::magnitudeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::package1::magnitudeResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::package1::magnitudeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f3a902f9783110e2b8fe7c475e26788e";
  }

  static const char* value(const ::package1::magnitudeResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf3a902f9783110e2ULL;
  static const uint64_t static_value2 = 0xb8fe7c475e26788eULL;
};

template<class ContainerAllocator>
struct DataType< ::package1::magnitudeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "package1/magnitudeResponse";
  }

  static const char* value(const ::package1::magnitudeResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::package1::magnitudeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 magnitude\n"
;
  }

  static const char* value(const ::package1::magnitudeResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::package1::magnitudeResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.magnitude);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct magnitudeResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::package1::magnitudeResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::package1::magnitudeResponse_<ContainerAllocator>& v)
  {
    s << indent << "magnitude: ";
    Printer<double>::stream(s, indent + "  ", v.magnitude);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PACKAGE1_MESSAGE_MAGNITUDERESPONSE_H
