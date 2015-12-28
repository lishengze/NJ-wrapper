class V8_EXPORT String : public Primitive {
   public:
   enum Encoding {
     UNKNOWN_ENCODING = 0x1,
     TWO_BYTE_ENCODING = 0x0,
      ASCII_ENCODING = 0x4,
      ONE_BYTE_ENCODING = 0x4
 1606   };
 1610   int Length() const;
 1611 
 1616   int Utf8Length() const;
 1617 
 1623   bool IsOneByte() const;
 1624 
 1629   bool ContainsOnlyOneByte() const;
 1630 
 1656   enum WriteOptions {
 1657     NO_OPTIONS = 0,
 1658     HINT_MANY_WRITES_EXPECTED = 1,
 1659     NO_NULL_TERMINATION = 2,
 1660     PRESERVE_ASCII_NULL = 4,
 1661     // Used by WriteUtf8 to replace orphan surrogate code units with the
 1662     // unicode replacement character. Needs to be set to guarantee valid UTF-8
 1663     // output.
 1664     REPLACE_INVALID_UTF8 = 8
 1665   };
 1666 
 1667   // 16-bit character codes.
 1668   int Write(uint16_t* buffer,
 1669             int start = 0,
 1670             int length = -1,
 1671             int options = NO_OPTIONS) const;
 1672   // One byte characters.
 1673   int WriteOneByte(uint8_t* buffer,
 1674                    int start = 0,
 1675                    int length = -1,
 1676                    int options = NO_OPTIONS) const;
 1677   // UTF-8 encoded characters.
 1678   int WriteUtf8(char* buffer,
 1679                 int length = -1,
 1680                 int* nchars_ref = NULL,
 1681                 int options = NO_OPTIONS) const;
 1682 
 1686   V8_INLINE static v8::Local<v8::String> Empty(Isolate* isolate);
 1687 
 1691   bool IsExternal() const;
 1692 
 1696   bool IsExternalAscii() const;
 1697 
 1698   class V8_EXPORT ExternalStringResourceBase {  // NOLINT
 1699    public:
 1700     virtual ~ExternalStringResourceBase() {}
 1701 
 1702    protected:
 1703     ExternalStringResourceBase() {}
 1704 
 1711     virtual void Dispose() { delete this; }
 1712 
 1713    private:
 1714     // Disallow copying and assigning.
 1715     ExternalStringResourceBase(const ExternalStringResourceBase&);
 1716     void operator=(const ExternalStringResourceBase&);
 1717 
 1718     friend class v8::internal::Heap;
 1719   };
 1720 
 1727   class V8_EXPORT ExternalStringResource
 1728       : public ExternalStringResourceBase {
 1729    public:
 1734     virtual ~ExternalStringResource() {}
 1735 
 1739     virtual const uint16_t* data() const = 0;
 1740 
 1744     virtual size_t length() const = 0;
 1745 
 1746    protected:
 1747     ExternalStringResource() {}
 1748   };
 1749 
 1761   class V8_EXPORT ExternalAsciiStringResource
 1762       : public ExternalStringResourceBase {
 1763    public:
 1768     virtual ~ExternalAsciiStringResource() {}
 1770     virtual const char* data() const = 0;
 1772     virtual size_t length() const = 0;
 1773    protected:
 1774     ExternalAsciiStringResource() {}
 1775   };
 1776 
 1777   typedef ExternalAsciiStringResource ExternalOneByteStringResource;
 1778 
 1784   V8_INLINE ExternalStringResourceBase* GetExternalStringResourceBase(
 1785       Encoding* encoding_out) const;
 1786 
 1791   V8_INLINE ExternalStringResource* GetExternalStringResource() const;
 1792 
 1797   const ExternalAsciiStringResource* GetExternalAsciiStringResource() const;
 1798 
 1799   V8_INLINE static String* Cast(v8::Value* obj);
 1800 
 1801   enum NewStringType {
 1802     kNormalString, kInternalizedString, kUndetectableString
 1803   };
 1804 
 1806   static Local<String> NewFromUtf8(Isolate* isolate,
 1807                                   const char* data,
 1808                                   NewStringType type = kNormalString,
 1809                                   int length = -1);
 1810 
 1812   static Local<String> NewFromOneByte(
 1813       Isolate* isolate,
 1814       const uint8_t* data,
 1815       NewStringType type = kNormalString,
 1816       int length = -1);
 1817 
 1819   static Local<String> NewFromTwoByte(
 1820       Isolate* isolate,
 1821       const uint16_t* data,
 1822       NewStringType type = kNormalString,
 1823       int length = -1);
 1824 
 1829   static Local<String> Concat(Handle<String> left, Handle<String> right);
 1830 
 1839   static Local<String> NewExternal(Isolate* isolate,
 1840                                    ExternalStringResource* resource);
 1841 
 1851   bool MakeExternal(ExternalStringResource* resource);
 1852 
 1861   static Local<String> NewExternal(Isolate* isolate,
 1862                                    ExternalAsciiStringResource* resource);
 1863 
 1873   bool MakeExternal(ExternalAsciiStringResource* resource);
 1874 
 1878   bool CanMakeExternal();
 1879 
 1887   class V8_EXPORT Utf8Value {
 1888    public:
 1889     explicit Utf8Value(Handle<v8::Value> obj);
 1890     ~Utf8Value();
 1891     char* operator*() { return str_; }
 1892     const char* operator*() const { return str_; }
 1893     int length() const { return length_; }
 1894    private:
 1895     char* str_;
 1896     int length_;
 1897 
 1898     // Disallow copying and assigning.
 1899     Utf8Value(const Utf8Value&);
 1900     void operator=(const Utf8Value&);
 1901   };
 1902 
 1909   class V8_EXPORT Value {
 1910    public:
 1911     explicit Value(Handle<v8::Value> obj);
 1912     ~Value();
 1913     uint16_t* operator*() { return str_; }
 1914     const uint16_t* operator*() const { return str_; }
 1915     int length() const { return length_; }
 1916    private:
 1917     uint16_t* str_;
 1918     int length_;
 1919 
 1920     // Disallow copying and assigning.
 1921     Value(const Value&);
 1922     void operator=(const Value&);
 1923   };
 1924 
 1925  private:
 1926   void VerifyExternalStringResourceBase(ExternalStringResourceBase* v,
 1927                                         Encoding encoding) const;
 1928   void VerifyExternalStringResource(ExternalStringResource* val) const;
 1929   static void CheckCast(v8::Value* obj);
 1930 };
 1931 