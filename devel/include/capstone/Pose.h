// Generated by gencpp from file capstone/Pose.msg
// DO NOT EDIT!


#ifndef CAPSTONE_MESSAGE_POSE_H
#define CAPSTONE_MESSAGE_POSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Twist.h>

namespace capstone
{
template <class ContainerAllocator>
struct Pose_
{
  typedef Pose_<ContainerAllocator> Type;

  Pose_()
    : header()
    , pose()  {
    }
  Pose_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , pose(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _pose_type;
  _pose_type pose;





  typedef boost::shared_ptr< ::capstone::Pose_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::capstone::Pose_<ContainerAllocator> const> ConstPtr;

}; // struct Pose_

typedef ::capstone::Pose_<std::allocator<void> > Pose;

typedef boost::shared_ptr< ::capstone::Pose > PosePtr;
typedef boost::shared_ptr< ::capstone::Pose const> PoseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::capstone::Pose_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::capstone::Pose_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::capstone::Pose_<ContainerAllocator1> & lhs, const ::capstone::Pose_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.pose == rhs.pose;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::capstone::Pose_<ContainerAllocator1> & lhs, const ::capstone::Pose_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace capstone

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::capstone::Pose_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capstone::Pose_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::capstone::Pose_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::capstone::Pose_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capstone::Pose_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capstone::Pose_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::capstone::Pose_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2a3c7e8205066a05578b341db14df4e6";
  }

  static const char* value(const ::capstone::Pose_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2a3c7e8205066a05ULL;
  static const uint64_t static_value2 = 0x578b341db14df4e6ULL;
};

template<class ContainerAllocator>
struct DataType< ::capstone::Pose_<ContainerAllocator> >
{
  static const char* value()
  {
    return "capstone/Pose";
  }

  static const char* value(const ::capstone::Pose_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::capstone::Pose_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"geometry_msgs/Twist pose\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Twist\n"
"# This expresses velocity in free space broken into its linear and angular parts.\n"
"Vector3  linear\n"
"Vector3  angular\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::capstone::Pose_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::capstone::Pose_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.pose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Pose_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::capstone::Pose_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::capstone::Pose_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAPSTONE_MESSAGE_POSE_H
