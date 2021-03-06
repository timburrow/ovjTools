/*
 * @(#)writer_history_interface.h    generated by: makeheader    Mon Dec  3 23:08:12 2007
 *
 *		built from:	interface.ifc
 */

#ifndef writer_history_interface_h
#define writer_history_interface_h



#ifndef writer_history_dll_h
#include "writer_history/writer_history_dll.h"
#endif

#ifndef osapi_ntptime_h
#include "osapi/osapi_ntptime.h"
#endif

#ifndef osapi_type_h
#include "osapi/osapi_type.h"
#endif

#ifndef reda_fastBuffer_h
#include "reda/reda_fastBuffer.h"
#endif

#ifndef mig_generator_h
#include "mig/mig_generator.h"
#endif

#ifndef mig_generator_h
#include "mig/mig_generator.h"
#endif

#ifndef commend_writerService_h
#include "commend/commend_writerService.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif


struct NDDS_WriterHistory_Plugin;

struct NDDS_WriterHistory_Listener;

typedef enum {
    /*e
      Keep just the last value.
    */
    NDDS_WRITERHISTORY_KEEP_LAST_HISTORY_QOS,

    /*e
      Keep all values.
    */
    NDDS_WRITERHISTORY_KEEP_ALL_HISTORY_QOS
} NDDS_WriterHistory_HistoryQosPolicyKind;

typedef enum {
    /*e
      Volatile.
    */
    NDDS_WRITERHISTORY_VOLATILE_DURABILITY_QOS,
    
    /*e
      Transient Local.
    */
    NDDS_WRITERHISTORY_TRANSIENT_LOCAL_DURABILITY_QOS,

    /*e
      Transient.
    */
    NDDS_WRITERHISTORY_TRANSIENT_DURABILITY_QOS,
    
    /*e
      Persistent.
    */
    NDDS_WRITERHISTORY_PERSISTENT_DURABILITY_QOS
} NDDS_WriterHistory_DurabilityQosPolicyKind;


#define NDDS_WRITERHISTORY_INFINITE_DURATION RTI_NTP_TIME_MAX

struct NDDS_WriterHistory_BufferProperty {
    /*e
      The buffer size.
    */
    RTI_UINT32 size;
    /*e
      The buffer alignment.
    */
    RTI_UINT32 alignment;
};

struct NDDS_WriterHistory_Property {
    /*e
      \brief This property indicates whether or not the WH is going to contain a single instance.

      That instance will be registered only once and it cannot be unregistered or disposed.

      This parameter property has been introduced for optimization purposes.
      A specific implementation of the writer history plugin can take advantage of it.
    */
    RTIBool singleInstance;
    /*e
      \brief Control growth in number of samples (not end coherent changes).

      The value of this property is obtained from DDS_ResourceLimitsQosPolicy.maxSamples 
      and DDS_ResourceLimitsQosPolicy.initialSamples.
    */
    struct REDAFastBufferPoolGrowthProperty sampleCount;
    /*e 
      \brief Control growth in number of instances. 

      The value of this property is obtained from the QoS 
      DDS_ResourceLimitsQosPolicy.maxInstances and DDS_ResourceLimitsQosPolicy.initialInstances.

      If the topic associated to the data writer is unkeyed, instanceCount.maximal
      should be 1 to take advantages of optimizations in the implementation.
    */
    struct REDAFastBufferPoolGrowthProperty instanceCount;
    /*e
      \brief The maximum allowable number of samples (without including end coherent changes)
      per instance. The value of this property is obtained from the QoS 
      DDS_ResourceLimitsQosPolicy.max_samples_per_instance.
    */
    RTI_INT32 maximalSamplePerInstanceCount;    
    /*e
      \brief Whether or not a sample should be made automatically reclaimable
      when is added to the WH.
    */
    RTIBool autoReclaimableOnAdd;
    /*e
      \brief Sacrifice non reclaimable samples.

      If there are not enough resource limits to satisfy the history depth
      when the history kind is KEEP_LAST but there are at least enough to
      satisfy a history depth of 1, the value denotes whether to sacrifice
      non reclaimable samples by dropping all but the last non reclaimable 
      sample of an instance if necessary in order to avoid blocking. */
    RTIBool sacrificeSamples;
    /*e 
      \brief The deadline period
    */
    struct RTINtpTime deadlinePeriod;
    /*e
      \brief History kind.
    */
    NDDS_WriterHistory_HistoryQosPolicyKind historyKind;
    /*e
      \brief How many values to keep in the instance history.
    */
    RTI_INT32 historyDepth;
    /*e
      \brief The durability kind.
    */
    NDDS_WriterHistory_DurabilityQosPolicyKind durabilityKind;
    /*e
      \brief The lifespan duration. 
      Maximum duration of validity of the data written by DataWriter
    */
    struct RTINtpTime lifespanDuration;
    /*e
      \brief Maximum size and alignment of the buffer used to store the serialized key
    */
    struct NDDS_WriterHistory_BufferProperty instanceKeyDataSize;
    /*e
      \brief Maximum size and alignment of the buffer used to store the serialized sample
    */
    struct NDDS_WriterHistory_BufferProperty sampleUserDataSize;
    /*e
      \brief Maximum size and alignment of the buffer used to store the sample inline QoS.
    */
    struct NDDS_WriterHistory_BufferProperty sampleInlineQosDataSize;
    /*e
      \brief Specifies whether resources and logic are allocated and enabled for 
      gathering statistics of this writer history plugin.
    */
    RTIBool gatherStatistics;
};

extern WRITERHISTORYDllExport
void NDDS_WriterHistory_Property_copy(struct NDDS_WriterHistory_Property * to,
                                      const struct NDDS_WriterHistory_Property * src);

typedef enum {
    /*e
      Data sample.
    */
    NDDS_WRITERHISTORY_DATA_SAMPLE = 0x00,
    /*e
      Unregister sample.
    */
    NDDS_WRITERHISTORY_UNREGISTER_SAMPLE = 0x01,
    /*e
      Dispose sample.
    */
    NDDS_WRITERHISTORY_DISPOSE_SAMPLE = 0x02,
    /*e
      Unregister/Dispose sample.
    */
    NDDS_WRITERHISTORY_UNREGISTER_DISPOSE_SAMPLE = 0x03,
    /*e
      End coherency sample.
    */
    NDDS_WRITERHISTORY_END_COHERENCY_SAMPLE  = 0x04
} NDDS_WriterHistory_SampleKind;

struct NDDS_WriterHistory_Sample {
    /*e
       \brief RTI DDS sample.
       This must be the first element as the entry "derives" from the sample. 
    */
    struct MIGGeneratorSample sample;
    /*e
      \brief Kind of sample.
    */
    NDDS_WriterHistory_SampleKind kind;
    /*e
      \brief Filter status.
    */
    struct COMMENDFilterStatus filterStatus;
};

struct NDDS_WriterHistory_Instance {
    /*e 
        \brief Instance GUID.
    */
    struct MIGRtpsGuid guid;
    /*e \brief Serialized key */
    struct REDABuffer keyData;
    /*e
      \brief Status of the instance.
    */
    RTIBool registered;
};

typedef void * NDDS_WriterHistory_Handle;

struct NDDS_WriterHistory_Statistics {
    /*e \brief entry count */
    RTI_UINT32 entryCountPeak;
};


#define NDDS_WRITER_HISTORY_STATISTICS_INITIALIZER { \
    0 /* entryCountPeak */ \
}


#define NDDS_WRITERHISTORY_RETCODE_OK 0


#define NDDS_WRITERHISTORY_RETCODE_PRECONDITION_NOT_MET 1


#define NDDS_WRITERHISTORY_RETCODE_FAILURE_INTERNAL 2


#define NDDS_WRITERHISTORY_RETCODE_FULL 3


#define NDDS_WRITERHISTORY_RETCODE_RESOURCE_CONTENTION 4


#define NDDS_WRITERHISTORY_RETCODE_OUT_OF_RESOURCES 5


#define NDDS_WRITERHISTORY_RETCODE_NO_INSTANCE 6


#define NDDS_WRITERHISTORY_RETCODE_NO_SAMPLE 7


#define NDDS_WRITERHISTORY_RETCODE_OUT_OF_ORDER 8


#define NDDS_WRITERHISTORY_RETCODE_LIFESPAN_EXPIRED 9


#define NDDS_WRITERHISTORY_RETCODE_EMPTY_COHERENT_SET 10


#define NDDS_WRITERHISTORY_RETCODE_NOT_SUPPORTED 11


#define NDDS_WRITERHISTORY_RETCODE_RESERVED_RANGE 100

struct NDDS_WriterHistory_OriginalWriterInfo {
    /*e
      Writer GUID.
    */
    struct MIGRtpsGuid writerGuid;
    /*e
      Writer Sequence Number.
    */
    struct REDASequenceNumber sequenceNumber;
};

extern WRITERHISTORYDllExport RTIBool
NDDS_WriterHistory_OriginalWriterInfo_equals(
    struct NDDS_WriterHistory_OriginalWriterInfo * self,
    const struct NDDS_WriterHistory_OriginalWriterInfo * other);

struct NDDS_WriterHistory_Attribute {
    /*e @brief Attribute name. NULL terminated string. */
    char * name;
    /*e @brief Attribute value. NULL terminated string. */
    char * value;
};

struct NDDS_WriterHistory_AttributeSeq {
    /*e @brief The maximum number of elements in the attribute sequence */
    RTI_UINT32 maximum;

    /*e @brief The number of elements in the attribute sequence */
    RTI_UINT32 length;

    /*e @brief The name,value pairs in the attribute sequence */
    struct NDDS_WriterHistory_Attribute * attributes;
};

extern WRITERHISTORYDllExport const char *
NDDS_WriterHistory_AttributeSeq_get_attribute_value(struct NDDS_WriterHistory_AttributeSeq * self,
                                                    const char * name);

extern WRITERHISTORYDllExport struct NDDS_WriterHistory_Attribute *
NDDS_WriterHistory_AttributeSeq_get_attribute(struct NDDS_WriterHistory_AttributeSeq * self,
                                              const char * name);

extern WRITERHISTORYDllExport int
NDDS_WriterHistory_AttributeSeq_compare(const struct NDDS_WriterHistory_AttributeSeq * left,
                                        const struct NDDS_WriterHistory_AttributeSeq * right);

typedef RTI_INT32 (*NDDS_WriterHistory_Listener_InitializeSampleCallback)(
    struct NDDS_WriterHistory_Listener * self,
    struct NDDS_WriterHistory_Sample * sample_inout,
    MIGGeneratorEndian endian_in,
    const struct NDDS_WriterHistory_OriginalWriterInfo * original_writer_info_in,
    RTIBool new_sample_in,
    const void * user_data_in /* Deserialized user sample */);

typedef RTI_INT32 (*NDDS_WriterHistory_Listener_FinalizeSampleCallback)(
    struct NDDS_WriterHistory_Listener * self,
    struct NDDS_WriterHistory_Sample * sample_out);

typedef RTI_INT32 (*NDDS_WriterHistory_Listener_InitializeInstanceCallback)(
    struct NDDS_WriterHistory_Listener * self,
    struct NDDS_WriterHistory_Instance * instance_inout,
    RTIBool new_instance_in,
    const void * key_data_in /* Deserialized user key */);

typedef RTI_INT32 (*NDDS_WriterHistory_Listener_FinalizeInstanceCallback)(
    struct NDDS_WriterHistory_Listener * self,
    struct NDDS_WriterHistory_Instance * instance_out);

struct NDDS_WriterHistory_Listener {
    /*e @brief Listener data

        A place for listener implementors to keep a pointer to data that may be 
        needed by their listener.
    */
    void * listener_data;
    /*e @brief Initializes a new sample added to the WH (not NULL).
    */
    NDDS_WriterHistory_Listener_InitializeSampleCallback initialize_sample;
    /*e @brief Finalizes a WH sample.
    */
    NDDS_WriterHistory_Listener_FinalizeSampleCallback finalize_sample;
    /*e @brief Initializes a new instance added to the WH (not NULL).
    */
    NDDS_WriterHistory_Listener_InitializeInstanceCallback initialize_instance;
    /*e @brief Finalizes a WH instance.
    */
    NDDS_WriterHistory_Listener_FinalizeInstanceCallback finalize_instance;
};

extern WRITERHISTORYDllExport void
NDDS_WriterHistory_Listener_initialize(struct NDDS_WriterHistory_Listener * listener);

extern WRITERHISTORYDllExport RTIBool
NDDS_WriterHistory_Listener_is_valid(struct NDDS_WriterHistory_Listener * listener);


#define NDDS_WRITERHISTORY_INVALID_PLUGIN_CLASSID (-1)


#define NDDS_WRITERHISTORY_ANY_PLUGIN_CLASSID (0)


#define NDDS_WRITERHISTORY_MEMORY_PLUGIN_CLASSID (1)  


#define NDDS_WRITERHISTORY_ODBC_PLUGIN_CLASSID (2)  


#define NDDS_WRITERHISTORY_RESERVED_RANGE_PLUGIN_CLASSID  (1000)

typedef int NDDS_WriterHistory_PluginClassId;

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_CreateHistoryFcn) (
        struct NDDS_WriterHistory_Plugin * self,
        NDDS_WriterHistory_Handle * history_out,
        const struct NDDS_WriterHistory_Property * property_in,
        const struct NDDS_WriterHistory_Listener * history_listener_in,
        const struct MIGRtpsGuid * dw_guid_in,
        const struct NDDS_WriterHistory_AttributeSeq * dw_property_in,
        struct RTIClock * clock_in,
        void * reserved);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_DestroyHistoryFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    NDDS_WriterHistory_Handle history_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_AddSampleFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    struct NDDS_WriterHistory_Sample ** sample_out,
    struct REDASequenceNumber * first_available_sn_out,
    NDDS_WriterHistory_Handle history_in,
    NDDS_WriterHistory_SampleKind kind_in,
    const struct MIGRtpsGuid * instance_guid_in,
    const struct RTINtpTime * timestamp_in,
    MIGGeneratorEndian endian_in,
    const void * user_data_in,
    const struct COMMENDFilterStatus * filter_status_in,
    const struct MIGRtpsGuid * reader_guid_in,
    const struct NDDS_WriterHistory_OriginalWriterInfo * original_writer_info_in,
    const struct RTINtpTime * now_in,
    RTIBool create_instance);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_ReturnSampleLoanFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    RTIBool * sample_reusable_out,
    NDDS_WriterHistory_Handle history_in,
    struct NDDS_WriterHistory_Sample * sample_in,
    const struct RTINtpTime * now_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_FindSampleFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    struct NDDS_WriterHistory_Sample ** sample_out,
    struct REDASequenceNumber * first_relevant_sn_out,
    struct REDASequenceNumber * next_relevant_sn_out,
    NDDS_WriterHistory_Handle history_in,
    const struct REDASequenceNumber *request_sn_in,
    const struct RTINtpTime *now_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_GetFirstAvailableSnFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    struct REDASequenceNumber * sn_out,
    NDDS_WriterHistory_Handle history_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_GetLastAvailableSnFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    struct REDASequenceNumber * sn_out,
    NDDS_WriterHistory_Handle history_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_GetFirstNonReclaimableSnFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    struct REDASequenceNumber * sn_out,
    NDDS_WriterHistory_Handle history_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_GetFirstSnInCoherentSetFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    struct REDASequenceNumber * sn_out,
    NDDS_WriterHistory_Handle history_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_ChangeFirstNonReclaimableSnFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    RTIBool * samples_reusable_out,
    NDDS_WriterHistory_Handle history_in,
    const struct REDASequenceNumber * first_non_reclaimable_sn_in,
    const struct RTINtpTime *now_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_MakeSampleReclaimableFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    RTIBool * sample_reusable_out,
    NDDS_WriterHistory_Handle history_in,
    struct NDDS_WriterHistory_Sample * sample_in,
    const struct REDASequenceNumber * sn_in,
    const struct RTINtpTime *now_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_GetNonReclaimableSamplesCountFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    RTI_INT32 * count_out,
    NDDS_WriterHistory_Handle history_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_SetLifespanFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    NDDS_WriterHistory_Handle history_in,
    const struct RTINtpTime * lifespan_duration_in,
    const struct RTINtpTime *now_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_PruneLifespanExpiredSamplesFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    RTIBool * samples_reusable_out,
    NDDS_WriterHistory_Handle history_in,
    const struct RTINtpTime *now_in,
    RTIBool single_sample_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_BeginCoherentChangesFcn) (
    struct NDDS_WriterHistory_Plugin * self,
    NDDS_WriterHistory_Handle history_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_BeginSampleIterationFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    NDDS_WriterHistory_Handle history_in,
    const struct REDASequenceNumber * sn_in,
    RTIBool end_previous_iteration_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_NextSampleFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    struct NDDS_WriterHistory_Sample ** sample_out,
    NDDS_WriterHistory_Handle history_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_EndSampleIterationFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    NDDS_WriterHistory_Handle history_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_RegisterInstanceFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    NDDS_WriterHistory_Handle history_in,
    const struct MIGRtpsGuid * instance_guid_in,
    const void * instance_data_in,    
    const struct RTINtpTime * timestamp_in,
    const struct RTINtpTime * now_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_UnregisterInstanceFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    NDDS_WriterHistory_Handle history_in,
    const struct MIGRtpsGuid * instance_guid_in,
    const struct RTINtpTime * timestamp_in,
    const struct RTINtpTime * now_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_FindInstanceFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    struct NDDS_WriterHistory_Instance ** instance_out,
    NDDS_WriterHistory_Handle history_in,
    const struct MIGRtpsGuid * instance_guid_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_ReturnInstanceLoanFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    RTIBool * instance_reusable_out,
    NDDS_WriterHistory_Handle history_in,
    struct NDDS_WriterHistory_Instance * instance_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_SetDeadlineFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    NDDS_WriterHistory_Handle history_in,
    const struct RTINtpTime * deadline_period_in,
    const struct RTINtpTime *now_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_CheckDeadlineFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    RTI_INT32 * deadline_missed_count_out,
    struct MIGRtpsGuid * last_instance_guid_out,
    struct RTINtpTime * min_next_deadline_out,
    NDDS_WriterHistory_Handle history_in,
    const struct RTINtpTime *now_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_BeginInstanceIterationFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    NDDS_WriterHistory_Handle history_in,
    const struct MIGRtpsGuid * instance_guid_in,
    RTIBool end_previous_iteration_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_NextInstanceFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    struct NDDS_WriterHistory_Instance ** instance_out,
    NDDS_WriterHistory_Handle history_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_EndInstanceIterationFcn)(
    struct NDDS_WriterHistory_Plugin * self,
    NDDS_WriterHistory_Handle history_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_InitializeFcn)(
        struct NDDS_WriterHistory_Plugin * self,
        const struct NDDS_WriterHistory_AttributeSeq * dp_properties_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_DestroyFcn)(
        struct NDDS_WriterHistory_Plugin * self);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_GetStatisticsFcn)(
        struct NDDS_WriterHistory_Plugin * self,
        struct NDDS_WriterHistory_Statistics *stats_out,
        NDDS_WriterHistory_Handle history_in);

typedef RTI_INT32 (*NDDS_WriterHistory_Plugin_ResetStatisticsFcn)(
        struct NDDS_WriterHistory_Plugin * self,
        NDDS_WriterHistory_Handle history_in);

struct NDDS_WriterHistory_Plugin {
    /*e @brief Plugin class
    */
    NDDS_WriterHistory_PluginClassId classId;
    /*e @brief Creates a new WH.
    */
    NDDS_WriterHistory_Plugin_CreateHistoryFcn create_history;
    /*e @brief Destroys a WH.
    */
    NDDS_WriterHistory_Plugin_DestroyHistoryFcn destroy_history;
    /*e @brief Adds a sample to the input WH.
    */
    NDDS_WriterHistory_Plugin_AddSampleFcn add_sample;
    /*e @brief Returns a sample loan.
    */
    NDDS_WriterHistory_Plugin_ReturnSampleLoanFcn return_sample_loan;
    /*e @brief Finds a sample in the input WH.
    */
    NDDS_WriterHistory_Plugin_FindSampleFcn find_sample;
    /*e @brief Returns the first available sequence number in the input WH.
    */
    NDDS_WriterHistory_Plugin_GetFirstAvailableSnFcn get_first_available_sn;
    /*e @brief Returns the last available sequence number in the input WH.
    */
    NDDS_WriterHistory_Plugin_GetLastAvailableSnFcn get_last_available_sn;
    /*e @brief Returns the first non reclaimable sequence number in the input WH.
    */
    NDDS_WriterHistory_Plugin_GetFirstNonReclaimableSnFcn get_first_non_reclaimable_sn;
    /*e @brief Returns the first sequence number in the coherent set for the input
        WH.
    */
    NDDS_WriterHistory_Plugin_GetFirstSnInCoherentSetFcn get_first_sn_in_coherent_set;
    /*e @brief Notifies the input WH that the first non reclaimable sequence number 
        has changed.
    */
    NDDS_WriterHistory_Plugin_ChangeFirstNonReclaimableSnFcn change_first_non_reclaimable_sn;
    /*e @brief Notifies the input WH that a sample must be made reclaimable.
    */
    NDDS_WriterHistory_Plugin_MakeSampleReclaimableFcn make_sample_reclaimable;
    /*e @brief Gets a count of the non-reclaimable samples.
    */
    NDDS_WriterHistory_Plugin_GetNonReclaimableSamplesCountFcn get_non_reclaimable_samples_count;
    /*e @brief Set the WH lifespan duration.
    */
    NDDS_WriterHistory_Plugin_SetLifespanFcn set_lifespan;
    /*e @brief Prunes WH lifespan expired samples.
    */
    NDDS_WriterHistory_Plugin_PruneLifespanExpiredSamplesFcn prune_lifespan_expired_samples;
    /*e @brief Begins a coherent change in the WH.
    */
    NDDS_WriterHistory_Plugin_BeginCoherentChangesFcn begin_coherent_changes;
    /*e @brief Begins an iterator access to the samples held by the input WH.
    */
    NDDS_WriterHistory_Plugin_BeginSampleIterationFcn begin_sample_iteration;
    /*e @brief Gets the next sample held by the input WH in iteration.
    */
    NDDS_WriterHistory_Plugin_NextSampleFcn next_sample;
    /*e @brief Ends iterator access to the samples held by the WH.
    */
    NDDS_WriterHistory_Plugin_EndSampleIterationFcn end_sample_iteration;
    /*e @brief Registers a WH instance.
    */
    NDDS_WriterHistory_Plugin_RegisterInstanceFcn register_instance;
    /*e @brief Unregisters a WH instance.
    */
    NDDS_WriterHistory_Plugin_UnregisterInstanceFcn unregister_instance;
    /*e @brief Finds an instance in the input WH.
    */
    NDDS_WriterHistory_Plugin_FindInstanceFcn find_instance;
    /*e @brief Returns an instance loan.
    */
    NDDS_WriterHistory_Plugin_ReturnInstanceLoanFcn return_instance_loan;
    /*e @brief Set the WH deadline period.
    */
    NDDS_WriterHistory_Plugin_SetDeadlineFcn set_deadline;
    /*e @brief Checks the WH instances deadline.
    */
    NDDS_WriterHistory_Plugin_CheckDeadlineFcn check_deadline;
    /*e @brief Begins an iterator access to the instances held by the input WH.
    */
    NDDS_WriterHistory_Plugin_BeginInstanceIterationFcn begin_instance_iteration;
    /*e @brief Gets the next instance held by the input WH in iteration.
    */
    NDDS_WriterHistory_Plugin_NextInstanceFcn next_instance;
    /*e @brief Ends iterator access to the instances held by the input WH.
    */
    NDDS_WriterHistory_Plugin_EndInstanceIterationFcn end_instance_iteration;
    /*e @brief Initializes the input WH plugin.
    */
    NDDS_WriterHistory_Plugin_InitializeFcn initialize;
    /*e @brief Destroys the input WH plugin.
    */
    NDDS_WriterHistory_Plugin_DestroyFcn destroy;
    /*e @brief Get statistics of th WH plugin.
    */
    NDDS_WriterHistory_Plugin_GetStatisticsFcn get_statistics;
    /*e @brief Reset statistics of th WH plugin.
    */
    NDDS_WriterHistory_Plugin_ResetStatisticsFcn reset_statistics;
};



#ifdef __cplusplus
    }	/* extern "C" */
#endif

#include "writer_history/writer_history_interface_impl.h"

#endif /* writer_history_interface_h */
